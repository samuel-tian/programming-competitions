#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

const int MAXN = 705;

template<class T, typename F> struct sparse_table {
	int sz;
	F comp;
	vector<vector<T> > st;
	sparse_table(const vector<T>& v, F func) {
		sz = v.size();
		comp = func;
		int depth = 1;
		for (int i = 1; i < sz; i *= 2) depth++;
		st.assign(depth, v);
		FOR (i, 0, depth - 1) {
			FOR (j, 0, sz) {
				st[i+1][j] = comp(st[i][j], st[i][min(sz - 1, j + (1<<i))]);
			}
		}
	}
	T query(int a, int b) {
		if (b < a) return INF;
		int depth = 31 - __builtin_clz(b - a);
		return comp(st[depth][a], st[depth][b - (1<<depth)]);
	}
};

template<class T, typename F> struct mono_queue {
	deque<pair<T, int> > q;
	F comp;
	mono_queue(F func) {
		this->comp = func;
	}
	void insert(pair<T, int> a) {
		while (!q.empty() && !comp(q.back().f, a.f)) {
			q.pop_back();
		}
		q.push_back(a);
	}
	void erase(int i) {
		while (q.front().s < i) {
			q.pop_front();
		}
	}
	T query(int i) {
		erase(i);
		return q.front().f;
	}
	void clear() {
		q.clear();
	}
};

struct Min {int operator() (int x, int y) {return min(x, y);}};
struct Max {int operator() (int x, int y) {return max(x, y);}};

int n, m, c;
vector<vector<int> > grid;
vector<sparse_table<int, Min> > rmin;
vector<sparse_table<int, Max> > rmax;


int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();
	setIO("stdio");
	cin >> m >> n >> c;
	grid.resize(n);
	FOR (i, 0, n) {
		grid[i].resize(m);
		FOR (j, 0, m) {
			cin >> grid[i][j];
		}
		rmin.pb(sparse_table<int, Min>(grid[i], Min()));
		rmax.pb(sparse_table<int, Max>(grid[i], Max()));
	}
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << endl;
	auto mpqmax = mono_queue<int, greater<int> >(greater<int>());
	auto mpqmin = mono_queue<int, less<int> >(less<int>());
	int ret = 0;
//	int x1, x2, y1, y2;
	FOR (i, 0, m) {
		FOR (j, i + 1, m+1) {
			if (j - i > 100) continue;
			mpqmax.clear(); mpqmin.clear();
			int hi = 0;
			FOR (lo, 0, n) {
				if (lo >= hi) {
					if ((j-i)*(hi-lo) > ret) {
						ret = (j-i)*(hi-lo);
//						x1 = i+1; y1 = n-hi+1; x2 = j; y2 = n-lo;
					}
					mpqmax.insert(mp(rmax[hi].query(i, j), hi));
					mpqmin.insert(mp(rmin[hi].query(i, j), hi));
					++hi;
				}
				while (hi < n && mpqmax.query(lo) - mpqmin.query(lo) <= c) {
					if ((j-i)*(hi-lo) > ret) {
						ret = (j-i)*(hi-lo);
//						x1 = i+1; y1 = n-hi+1; x2 = j; y2 = n-lo;
					}
					mpqmax.insert(mp(rmax[hi].query(i, j), hi));
					mpqmin.insert(mp(rmin[hi].query(i, j), hi));
					++hi;
				}
			}
		}
	}
	cout << ret << endl;
//	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	t1 = chrono::high_resolution_clock::now();
//	cout << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << endl;
}
