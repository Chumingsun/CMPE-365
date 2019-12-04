#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include<queue>
using namespace std;
#define MAX_TREE_HT 256
map<char, string> codes;
map<char, int> freq;
struct MinHeapNode {
	char data;
	int freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, int freq) {
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};
struct compare {
	bool operator()(MinHeapNode* l, MinHeapNode* r) {
		return (l->freq > r->freq);
	}
};
void printCodes(struct MinHeapNode* root, string str) {
	if (!root) return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}
void storeCodes(struct MinHeapNode* root, string str) {
	if (root == NULL) return;
	if (root->data != '$')
		codes[root->data] = str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
void HuffmanCodes() {
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}
void calcFreq(string fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "File not found\n";
		exit(0);
	}
	string str = "";
	while (getline(file, str)) {
		for (int i = 0; i < str.size(); i++)
			freq[str[i]]++;
		freq[10]++;
	}
	file.close();
}
void encode_file(string fileName, string eFileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Fiile not found\n";
		exit(0);
	}
	ofstream eFile(eFileName);
	string str = "";
	getline(file, str);
	if (str.size() || !eFile.eof()) {
		while (true) {
			for (auto i : str)
				eFile << codes[i];
			if (getline(file, str))
				eFile << codes[(char)(10)];
			else break;
		}
	}
	eFile.close();
	file.close();
}
void decode_file(struct MinHeapNode* root, string eFileName, string dFileName)
{
	ifstream eFile(eFileName);
	if (!eFile.is_open()) {
		cout << "Fiile not found\n";
		exit(0);
	}
	ofstream dFile(dFileName);
	struct MinHeapNode* curr = root;
	string s;
	while (getline(eFile, s)) {
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '0')
				curr = curr->left;
			else curr = curr->right;
			if (curr->left == NULL && curr->right == NULL)
			{
				dFile << curr->data;
				curr = root;
			}
		}
	}
	dFile.close();
	eFile.close();
}
int main()
{
	string fileName = "File2.txt";
	string cFileName = "codesFile2.txt";
	string eFileName = "EncodedFile2.txt";
	string dFileName = "DecodedFile2.txt";
	calcFreq(fileName);
	HuffmanCodes();
	ofstream cFile(cFileName);
	for (auto v = codes.begin(); v != codes.end(); v++) {
		cFile << (char)v->first << ' ' << v->second << endl;
	}
	cFile.close();
	encode_file(fileName, eFileName);
	decode_file(minHeap.top(), eFileName, dFileName);
	return 0;
}
