/*
 * Trie
 * ----
 * - a tree where
 * 		- edges represent characters
 * 		- nodes represent words, which are formed by concatenating the characters represented by the edges traversed from the root
 * - uses
 * 		- sort words in alphabetical order
 * 		- insert and find strings in O(L)
 * 		- prefix searches
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef long long ll;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 30005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "input") {
		freopen("input.txt","r",stdin);
	}
	else if (name == "stdio") {

	}
	else {
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
}

const int MAXC = 26;
struct node {
	node *c[MAXC];
	bool is_end;
	node() {
		FOR (i, 0, MAXC) {
			this->c[i] = NULL;
			this->is_end = false;
		}
	}
	void insert(string &s, int i) {
		if (i == s.size()) {
			this->is_end = true;
			return;
		}
		int k = s[i] - 'a';
		if (this->c[k] == NULL) {
			this->c[k] = new node();
		}
		c[k]->insert(s, i+1);
	}
};

int n;
string s[MAXN];
vi adj[MAXN];
bool prefix;

void dfs(node* iter, string s, int i) {
	if (i == s.size()) return;
	if (iter->is_end) {
		prefix = true;
		return;
	}
	int k = s[i] - 'a';
	FOR (j, 0, MAXC) {
		if (j != k && iter->c[j] != NULL) {
			adj[k].pb(j);
		}
	}
	dfs(iter->c[k], s, i+1);
}

int main() {
	setIO("stdio");
	node* trie = new node();
	cin >> n;
	FOR (i, 0, n) {
		cin >> s[i];
		trie->insert(s[i], 0);
	}
}