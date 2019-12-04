"LCS.py"

Requires:
	<*>numpy and xxhash

How to Run:
	<*> It requires two filenames as its argument
	<*>python LCS.py filename1 filename2

Method Used to represent strings by integers:
	<*>xxhash
	<*>hashing was the perfect solution!
	<*>xxhash was the fastest non-cryptographic hashing algorithm upto 11/23/2019
	<*>heres a comparison
	 Name            Speed       Q.Score   Author
	 xxHash          5.4 GB/s     10
	 MumurHash 3a    2.7 GB/s     10       Austin Appleby
	 SpookyHash      2.0 GB/s     10       Bob Jenkins
	 SBox            1.4 GB/s      9       Bret Mulvey
	 Lookup3         1.2 GB/s      9       Bob Jenkins
	 CityHash64      1.05 GB/s    10       Pike & Alakuijala
	 FNV             0.55 GB/s     5       Fowler, Noll, Vo
	 CRC32           0.43 GB/s     9
	 MD5-32          0.33 GB/s    10       Ronald L. Rivest
	 SHA1-32         0.28 GB/s    10


Results:

				"Dijkstra.py vs Dijkstra_py3.py"

Match:   Dijkstra.py: <1 .. 2>  Dijkstra_py3.py: <1 .. 2>


Mismatch:        Dijkstra.py: <3 .. 3>  Dijkstra_py3.py: <3 .. 3>


Match:   Dijkstra.py: <4 .. 6>  Dijkstra_py3.py: <4 .. 6>


Mismatch:        Dijkstra.py: <7 .. 6>  Dijkstra_py3.py: <7 .. 8>


Match:   Dijkstra.py: <7 .. 9>  Dijkstra_py3.py: <9 .. 11>


Mismatch:        Dijkstra.py: <10 .. 11>        Dijkstra_py3.py: <12 .. 11>


Match:   Dijkstra.py: <12 .. 15>        Dijkstra_py3.py: <12 .. 15>


Mismatch:        Dijkstra.py: <16 .. 16>        Dijkstra_py3.py: <16 .. 16>


Match:   Dijkstra.py: <17 .. 33>        Dijkstra_py3.py: <17 .. 33>


Mismatch:        Dijkstra.py: <34 .. 35>        Dijkstra_py3.py: <34 .. 33>


Match:   Dijkstra.py: <36 .. 36>        Dijkstra_py3.py: <34 .. 34>


Mismatch:        Dijkstra.py: <37 .. 36>        Dijkstra_py3.py: <35 .. 35>


Match:   Dijkstra.py: <37 .. 61>        Dijkstra_py3.py: <36 .. 60>


Mismatch:        Dijkstra.py: <62 .. 65>        Dijkstra_py3.py: <61 .. 64>


Match:   Dijkstra.py: <66 .. 73>        Dijkstra_py3.py: <65 .. 72>


Mismatch:        Dijkstra.py: <74 .. 78>        Dijkstra_py3.py: <73 .. 77>


Match:   Dijkstra.py: <79 .. 89>        Dijkstra_py3.py: <78 .. 88>


Mismatch:        Dijkstra.py: <90 .. 90>        Dijkstra_py3.py: <89 .. 89>


Match:   Dijkstra.py: <91 .. 101>       Dijkstra_py3.py: <90 .. 100>


Mismatch:        Dijkstra.py: <102 .. 103>      Dijkstra_py3.py: <101 .. 102>


Match:   Dijkstra.py: <104 .. 104>      Dijkstra_py3.py: <103 .. 103>


Mismatch:        Dijkstra.py: <105 .. 105>      Dijkstra_py3.py: <104 .. 104>


Match:   Dijkstra.py: <106 .. 106>      Dijkstra_py3.py: <105 .. 105>


Mismatch:        Dijkstra.py: <107 .. 109>      Dijkstra_py3.py: <106 .. 110>

						
						
						
						
						"Three_Bears.v1.txt vs Three_Bears.v2.txt"
						
						
						
						
						
Match:   Three_Bears.v1.txt: <1 .. 15>  Three_Bears.v2.txt: <1 .. 15>


Mismatch:        Three_Bears.v1.txt: <16 .. 18> Three_Bears.v2.txt: <16 .. 19>


Match:   Three_Bears.v1.txt: <19 .. 19> Three_Bears.v2.txt: <20 .. 20>


Mismatch:        Three_Bears.v1.txt: <20 .. 20> Three_Bears.v2.txt: <21 .. 21>


Match:   Three_Bears.v1.txt: <21 .. 21> Three_Bears.v2.txt: <22 .. 22>


Mismatch:        Three_Bears.v1.txt: <22 .. 22> Three_Bears.v2.txt: <23 .. 23>


Match:   Three_Bears.v1.txt: <23 .. 24> Three_Bears.v2.txt: <24 .. 25>


Mismatch:        Three_Bears.v1.txt: <25 .. 25> Three_Bears.v2.txt: <26 .. 26>


Match:   Three_Bears.v1.txt: <26 .. 31> Three_Bears.v2.txt: <27 .. 32>


Mismatch:        Three_Bears.v1.txt: <32 .. 32> Three_Bears.v2.txt: <33 .. 33>


Match:   Three_Bears.v1.txt: <33 .. 34> Three_Bears.v2.txt: <34 .. 35>


Mismatch:        Three_Bears.v1.txt: <35 .. 35> Three_Bears.v2.txt: <36 .. 37>


Match:   Three_Bears.v1.txt: <36 .. 39> Three_Bears.v2.txt: <38 .. 41>


Mismatch:        Three_Bears.v1.txt: <40 .. 41> Three_Bears.v2.txt: <42 .. 43>


Match:   Three_Bears.v1.txt: <42 .. 42> Three_Bears.v2.txt: <44 .. 44>


Mismatch:        Three_Bears.v1.txt: <43 .. 43> Three_Bears.v2.txt: <45 .. 45>


Match:   Three_Bears.v1.txt: <44 .. 51> Three_Bears.v2.txt: <46 .. 53>


Mismatch:        Three_Bears.v1.txt: <52 .. 52> Three_Bears.v2.txt: <54 .. 54>


Match:   Three_Bears.v1.txt: <53 .. 58> Three_Bears.v2.txt: <55 .. 60>


Mismatch:        Three_Bears.v1.txt: <59 .. 59> Three_Bears.v2.txt: <61 .. 61>


Match:   Three_Bears.v1.txt: <60 .. 72> Three_Bears.v2.txt: <62 .. 74>


Mismatch:        Three_Bears.v1.txt: <73 .. 74> Three_Bears.v2.txt: <75 .. 76>


Match:   Three_Bears.v1.txt: <75 .. 80> Three_Bears.v2.txt: <77 .. 82>


Mismatch:        Three_Bears.v1.txt: <81 .. 81> Three_Bears.v2.txt: <83 .. 83>


Match:   Three_Bears.v1.txt: <82 .. 86> Three_Bears.v2.txt: <84 .. 88>


Mismatch:        Three_Bears.v1.txt: <87 .. 88> Three_Bears.v2.txt: <89 .. 88>


Match:   Three_Bears.v1.txt: <89 .. 93> Three_Bears.v2.txt: <89 .. 93>


Mismatch:        Three_Bears.v1.txt: <94 .. 94> Three_Bears.v2.txt: <94 .. 94>


Match:   Three_Bears.v1.txt: <95 .. 100>        Three_Bears.v2.txt: <95 .. 100>


Mismatch:        Three_Bears.v1.txt: <101 .. 101>       Three_Bears.v2.txt: <101 .. 101>


Match:   Three_Bears.v1.txt: <102 .. 108>       Three_Bears.v2.txt: <102 .. 108>


Mismatch:        Three_Bears.v1.txt: <109 .. 109>       Three_Bears.v2.txt: <109 .. 109>


Match:   Three_Bears.v1.txt: <110 .. 115>       Three_Bears.v2.txt: <110 .. 115>


Mismatch:        Three_Bears.v1.txt: <116 .. 116>       Three_Bears.v2.txt: <116 .. 116>


Match:   Three_Bears.v1.txt: <117 .. 124>       Three_Bears.v2.txt: <117 .. 124>


Mismatch:        Three_Bears.v1.txt: <125 .. 128>       Three_Bears.v2.txt: <125 .. 127>


Match:   Three_Bears.v1.txt: <129 .. 130>       Three_Bears.v2.txt: <128 .. 129>