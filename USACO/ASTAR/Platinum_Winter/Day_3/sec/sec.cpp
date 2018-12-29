#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXN 50000
#define INF INT_MAX

struct TrieNode {
	int isword;
	int wordsbefore, wordsafter;
	TrieNode* children[2];
};

TrieNode* newnode() {
	TrieNode* t = new TrieNode;
	t->isword = 0;
	t->wordsbefore = 0;
	t->wordsafter = 0;
	for (int i = 0; i < 2; ++i) {
		t->children[i] = NULL;
	}
	return t;
}

void insert(TrieNode* root, string key) {
	TrieNode* current = root;
	for (int i = 0; i < key.size(); ++i) {
		int val = key[i] - '0';
		if (current->children[val] == NULL) {
			current->children[val] = newnode();
		}
		current = current->children[val];
	}
	current->isword += 1;
}

int updatewordsbefore(TrieNode* current, int counter) {
	for (int i = 0; i < 2; ++i) {
		if (current->children[i] == NULL) continue;
		updatewordsbefore(current->children[i], counter + current->isword);
	}
	current->wordsbefore = counter + current->isword;
	return current->wordsbefore;
}

int updatewordsafter(TrieNode* current) {
	if (current->children[0] == NULL && current->children[1] == NULL) {
		current->wordsafter = current->isword;
		return current->wordsafter;
	}
	int sum = 0;
	for (int i = 0; i < 2; ++i) {
		if (current->children[i] == NULL) continue;
		sum += updatewordsafter(current->children[i]);
	}
	current->wordsafter = sum + current->isword;
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
	return current->wordsafter + current->wordsbefore - current->isword;
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
	}
	updatewordsbefore(trie, 0);
	updatewordsafter(trie);
	for (int i = 0; i < m; ++i) {
		cout << search(trie, codewords[i]) << endl;
	}
	return 0;
}
