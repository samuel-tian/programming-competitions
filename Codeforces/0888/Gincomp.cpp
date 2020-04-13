#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

const int MAXC = 2;
struct node {
	node *c[MAXC], *par;
	bool is_end;
	int id, ind, cnt;
	node() {
		FOR (i, 0, MAXC) {
			this->c[i] = NULL;
		}
		this->par = NULL;
		this->id = -1;
		this->ind = this->cnt = this->is_end = 0;
	}
};
struct trie {
	node* root;
	int sz;
	trie() {
		this->root = new node();
		sz = 31;
	}
	void insert(int s, int id) {
		node *rt = this->root;
		FOR (i, 0, sz) {
			int k = (s & (1<<(sz-1-i))) ? 1 : 0;
			if (rt->c[k] == NULL) {
				rt->c[k] = new node();
				rt->c[k]->par = rt;
				rt->cnt++;
			}
			rt = rt->c[k];
			rt->ind = k;
		}
		rt->is_end = true;
		rt->id = id;
	}
	void remove(int s) {
		node *rt = this->root;
		FOR (i, 0, sz) {
			int k = (s & (1<<(sz-1-i))) ? 1 : 0;
			rt = rt->c[k];
		}
		rt->is_end = false;
		while (rt->cnt == 0 && !rt->is_end) {
			node* p = rt;
			rt = rt->par;
			rt->c[p->ind] = NULL;
			delete p;
			rt->cnt--;
		}
	}
	int closest_match(int s) {
		node* rt = this->root;
		FOR (i, 0, sz) {
			int k = (s & (1<<(sz-1-i))) ? 1 : 0;
			if (rt->c[k] == NULL) {
				rt = rt->c[1-k];
			}
			else {
				rt = rt->c[k];
			}
		}
		return rt->id;
	}
};

const int MAXN = 200005;
int par[MAXN];
int r[MAXN];

int find(int i) {
	if (par[i] != i) {
		par[i] = find(par[i]);
	}
	return par[i];
}

void unionRank(int aa, int bb) { // append b to a
	int a = find(aa);
	int b = find(bb);
	if (r[b] > r[a]) {
		unionRank(bb, aa);
		return;
	}
	par[b] = a;
	r[a] = max(r[a], r[b] + 1);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();
	setIO("input");
	int n;
	cin >> n;
	int a[n];
	trie* t = new trie();
	FOR (i, 0, n) {
		cin >> a[i];
		t->insert(a[i], i);
	}
	int num_trees = n;
	ll ret = 0;
	vi comps[n];
	FOR (i, 0, n) {
		par[i] = i;
	}
	while (num_trees > 1) {
		FOR (i, 0, n) {
			comps[i].clear();
		}
		FOR (i, 0, n) {
			comps[find(i)].pb(i);
		}
		FOR (i, 0, n) {
			if (comps[i].empty()) continue;
			for (int j : comps[i]) {
				t->remove(a[j]);
			}
			int min_match = INF, min_k = -1, min_j = -1;
			for (int j : comps[i]) {
				int k = t->closest_match(a[j]);
				if ((a[k] ^ a[j]) < min_match) {
					min_match = a[k] ^ a[j];
					min_k = k;
					min_j = j;
				}
			}
			if (find(min_k) != find(min_j)) {
				unionRank(min_j, min_k);
//				cout << "union: " << min_j << " " << min_k << endl;
				num_trees--;
				ret += min_match;
			}
			for (int j : comps[i]) {
				t->insert(a[j], j);
			}
			/*FOR (i, 0, n) {
				cout << find(i) << " ";
			}
			cout << endl;*/
		}
	}
	cout << ret << endl;
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << endl;
}
