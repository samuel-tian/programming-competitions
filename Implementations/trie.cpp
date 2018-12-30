#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXN 50000
#define INF INT_MAX
#define ALPHABET 2

struct TrieNode {
	int isword;
	TrieNode* children[ALPHABET];
};

TrieNode* newnode() {
	TrieNode* t = new TrieNode;
	t->isword = 0;
	for (int i = 0; i < ALPHABET; ++i) {
		t->children[i] = NULL;
	}
	return t;
}

void insert(TrieNode* root, string key) {
	TrieNode* current = root;
	for (int i = 0; i < key.size(); ++i) {
		int val = key[i] - 'a'; // assuming that the used alphabet begins with 'a'
		if (current->children[val] == NULL) {
			current->children[val] = newnode();
		}
		current = current->children[val];
	}
	current->isword += 1;
}


int main() {
	TrieNode* trie = newnode();
	return 0;
}
