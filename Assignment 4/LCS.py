#Tested with Python 3.8
#Requires numpy and xxhash
#10196230 / Chu Ming Sun
import sys
import xxhash
import numpy


def compare(fil1, fil2):
    #reading and splitting the files in lines
    f1 = fil1.read()
    f2 = fil2.read()
    f1 = f1.rsplit("\n")
    f2 = f2.rsplit("\n")
    #initiating hash dictionaries format is {line#,Stringhash}
    f1hash = {}
    f2hash = {}
    #calculating and populating String/hash dictionary for file 1
    for i, line in enumerate(f1):
        f1hash[i+1] = (xxhash.xxh32(line).intdigest())
    # calculating and populating String/hash dictionary for file 2
    for i, line in enumerate(f2):
        f2hash[i+1] = (xxhash.xxh32(line).intdigest())

    #initiating the lcs table using numpy
    lcsTable = numpy.zeros([list(f2hash.values()).__len__() + 1, list(f1hash.values()).__len__() + 1], dtype=numpy.uint32)
    #populating the lcs table using the algo
    for i in range(list(f2hash.values()).__len__() + 1):
        for j in range(list(f1hash.values()).__len__() + 1):
            #fill the second row and column with zero also the first entry of table and second entry of 2nd row and column
            if (i == 0 and j == 0) or (i == 1 and j == 1) or (i == 1 and j > 1) or (j == 1 and i > 1):
                lcsTable[i][j] = 0
            elif i == 0 and j > 1:#Fill the first row with file1 string hashes
                lcsTable[i][j] = list(f1hash.values())[j - 1]
            elif j == 0 and i > 1:#Fill the first column with file2 string hashes
                lcsTable[i][j] = list(f2hash.values())[i - 1]
            elif i > 1 and j > 1:#the algorithm
                if lcsTable[0][j] == lcsTable[i][0]:#if strings are same than fill diagonal value + 1
                    lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1
                else:#if strings are not same than fill max of top and left cell
                    lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1])
    print(lcsTable)
    print("\n\n\n\n\n\n\n")
    #preparing for traceback loop
    i = list(f2hash.values()).__len__()
    j = list(f1hash.values()).__len__()
    # it is used to track whan the lines start matching/mismatching during the current sequence
    f1matchstart = 0
    f1mismatchstart = 0
    f2matchstart = 0
    f2mismatchstart = 0
    if max(lcsTable[i - 1][j], lcsTable[i][j - 1]) == lcsTable[i][j]:
        f1mismatchstart = j - 1
        f2mismatchstart = i - 1
    else:
        f1matchstart = j - 1
        f2matchstart = i - 1

    result = []#this holds the final result
    #traceback loop
    while True:
        if lcsTable[i][j] == 0:#if traceback finished
            if f1matchstart != 0:
                result.append("Match:\t " + fil1.name + ": <" + list(f1hash.keys())[j-1].__str__() + " .. " + list(f1hash.keys())[f1matchstart].__str__() + ">\t" + fil2.name + ": <" + list(f2hash.keys())[i-1].__str__() + " .. " + list(f2hash.keys())[f2matchstart].__str__() + ">\t")
            elif f1mismatchstart != 0:
                result.append("Mismatch:\t " + fil1.name + ": <" + list(f1hash.keys())[j].__str__() + " .. " + list(f1hash.keys())[f1mismatchstart].__str__() + ">\t" + fil2.name + ": <" + list(f2hash.keys())[i-1].__str__() + " .. " + list(f2hash.keys())[f2mismatchstart].__str__() + ">")
            break
        if max(lcsTable[i - 1][j], lcsTable[i][j - 1]) == lcsTable[i][j]:#if the cell is a result of max top and left cell i.e mismatch
            if f1matchstart != 0:
                result.append("Match:\t " + fil1.name + ": <" + list(f1hash.keys())[j].__str__() +
                      " .. " + list(f1hash.keys())[f1matchstart].__str__() + ">\t" + fil2.name + ": <" +
                      list(f2hash.keys())[i].__str__() + " .. " +
                      list(f2hash.keys())[f2matchstart].__str__() + ">\t")
                f1matchstart = 0
                f2matchstart = 0
                f1mismatchstart = j-1
                f2mismatchstart = i-1
            if lcsTable[i][j] == lcsTable[i - 1][j]:
                i -= 1
            else:
                j -= 1
        else:#if the cell is a result of diagonal + 1 i.e match
            if f1mismatchstart != 0:
                result.append("Mismatch:\t " + fil1.name + ": <" + list(f1hash.keys())[j].__str__() + " .. " + list(f1hash.keys())[f1mismatchstart].__str__() + ">\t" + fil2.name + ": <" + list(f2hash.keys())[i].__str__() + " .. " + list(f2hash.keys())[f2mismatchstart].__str__() + ">")
                f1mismatchstart = 0
                f2mismatchstart = 0
                f1matchstart = j - 1
                f2matchstart = i - 1

            i -= 1
            j -= 1
    #print the result in reverse to get the result in correct order
    for i in result.__reversed__():
        print(i)
        print("\n")





#**************************Main function************************

# The command line is 
#
#   LCS.py {input filename1} {input filename2}


if len(sys.argv) < 3:
    sys.stderr.write( 'Usage: LCS.py {input filename1} {input filename2}\n' )
    sys.exit(1)

# Get file 1
try:
    file1 = open(sys.argv[1])
except:
    sys.stderr.write("Could not open input file '%s'.\n" % sys.argv[1])
    sys.exit(1)

# Get file 2

try:
    file2 = open(sys.argv[2])
except:
    sys.stderr.write("Could not open input file '%s'.\n" % sys.argv[2])
    sys.exit(1)

# Run the algorithm

compare(file1, file2)
