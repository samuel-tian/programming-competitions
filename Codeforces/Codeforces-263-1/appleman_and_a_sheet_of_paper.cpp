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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

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

struct sum_seg_tree {
	int n;
	int segTree[MAXSEG];
	sum_seg_tree() {
		this->n = 0;
		fill(segTree, segTree + MAXSEG, 0);
	}
	sum_seg_tree(int n) {
		this->n = n;
		fill(segTree, segTree + MAXSEG, 0);
	}
	int query(int i, int j) {
		return queryUtil(0, 0, n-1, i, j);
	}
	int queryUtil(int node, int a, int b, int i, int j) {
		if (a >= i && b <= j) {
			return segTree[node];
		}
		if (a > j || b < i) {
			return 0;
		}
		int mid = (a + b) / 2;
		int l = queryUtil(2 * node + 1, a, mid, i, j);
		int r = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return l + r;
	}
	void update(int i, int val) {
		updateUtil(0, 0, n-1, i, val);
	}
	void updateUtil(int node, int a, int b, int i, int val) {
		if (i < a || i > b) {
			return;
		}
		if (a == b) {
			segTree[node] += val;
		}
		else if (a != b) {
			int mid = (a + b) / 2;
			updateUtil(2 * node + 1, a, mid, i, val);
			updateUtil(2 * node + 2, mid + 1, b, i, val);
			segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
		}
	}
};

int n, q;

int main() {
	setIO("stdio");
	cin >> n >> q;
	sum_seg_tree segTree(n);
	FOR (i, 0, n) {
		segTree.update(i, 1);
	}
	int type;
	int start = 0, length = n, flipped = 0;
	FOR (query, 0, q) {
		cin >> type;
		if (type == 1) {
			int a;
			cin >> a;
//			cout << "query" << " " << 1 << " " << a << endl;
			if (!flipped) {
				if (a > length / 2) {
					flipped ^= 1;
					FOR (i, a, length) {
						int v = segTree.query(i + start, i + start);
						segTree.update(2*a-i-1+start, v);
					}
					length = a;
				}
				else {
					FORd (i, a - 1, 0) {
						int v = segTree.query(i + start, i + start);
						segTree.update(2*a-i-1+start, v);
					}
					start = start + a;
					length = length - a;
				}
			}
			else if (flipped) {
				a = length - a;
				if (a <= length / 2) {
					flipped ^= 1;
					FORd (i, a - 1, 0) {
						int v = segTree.query(i + start, i + start);
						segTree.update(2*a-i-1+start, v);
					}
					start = start + a;
					length = length - a;
				}
				else {
					FOR (i, a, length) {
						int v = segTree.query(i + start, i + start);
						segTree.update(2*a-i-1+start, v);
					}
					length = a;
				}
			}
		}
		else if (type == 2) {
			int a, b;
			cin >> a >> b;
//			cout << "query" << " " << 2 << " " << a << " " << b << endl;
			if (!flipped) {
				cout << segTree.query(a + start, b - 1 + start) << endl;
			}
			else {
				a = length - a;
				b = length - b;
				cout << segTree.query(b + start, a + start - 1) << endl;
			}
		}
		/*cout << start << " " << length << " " << flipped << ", ";
		FOR (i, start, start + length) {
			cout << segTree.query(i, i) << " ";
		}
		cout << endl;*/
	}
}
