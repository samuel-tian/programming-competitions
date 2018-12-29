#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50000

struct TrieNode {
	int wordsbefore, wordsafter;
	TrieNode* children[2];
	// children[0] represents 0, children[1] represents 1
	int isword;
	// may need to change this to an int to account for repeated keys
};

TrieNode* newnode() {
	TrieNode* t = new TrieNode;
	t->wordsbefore = 0;
	t->wordsafter = 0;
	t->isword = 0;
	for (int i = 0; i < 2; ++i) {
		t->children[i] = NULL;
	}
	return t;
}

void insert(TrieNode* root, string key) {
	TrieNode* current = root;
	for (int i = 0; i < key.size(); ++i) {
		int val = key[i] - '0';
		if (!current->children[val]) {
			current->children[val] = newnode();
			current->children[val]->wordsbefore = current->wordsbefore;
		}
		current = current->children[val];
	}
	++(current->isword);
	++(current->wordsbefore);
}

int updatewordsafter(TrieNode* current) {
	cout << "ISWORD: " << current->isword << endl;
	int b = true;
	for (int i = 0; i < 2; ++i) {
		if (current->children[i] != NULL) {
			b = false;
			break;
		}
	}
	if (b) {
		current->wordsafter = current->isword != 0 ? 1 : 0;
		return current->wordsafter; // should always be 0 because all the leafs are words
	}
	int sum = 0;
	for (int i = 0; i < 2; ++i) {
		if (current->children[i] == NULL) continue;
		sum += updatewordsafter(current->children[i]);
	}
	current->wordsafter = current->isword != 0 ? sum + 1 : sum;
	return current->wordsafter;
}

int search(TrieNode* root, string key) {
	TrieNode* current = root;
	for (int i = 0; i < key.size(); ++i) {
		int val = key[i] - '0';
		if (current->children[val] == NULL) {
			return current->wordsbefore;
		}
		current = current->children[val];
	}
	return current->wordsafter;
}

int n, m;
TrieNode* trie = newnode();
string codewords[MAXN];
string intercepted[MAXN];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int l;
		cin >> l;
		char c;
		intercepted[i] = "";
		for (int j = 0; j < l; ++j) {
			cin >> c;
			intercepted[i] = intercepted[i] + c;
		}
		insert(trie, intercepted[i]);
	}
	for (int i = 0; i < m; ++i) {
		int l;
		cin >> l;
		char c;
		for (int j = 0; j < l; ++j) {
			cin >> c;
			codewords[i] = codewords[i] + c;
		}
		insert(trie, codewords[i]);
	}
	cout << updatewordsafter(trie) << endl;
	cout << "UPDATE: " << updatewordsafter(trie->children[1]->children[1]->children[0]) << endl;
	// int ret = 0;
	for (int i = 0; i < m; ++i) {
		cout << search(trie, codewords[i]) << endl;
	}
	// cout << ret << endl;
	return 0;
}
