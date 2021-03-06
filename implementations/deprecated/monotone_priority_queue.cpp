/*
 * Monotone Priority Queue (MPQ)
 * -----------------------------
 * - an MPQ satisfies the invariant that mpq[i] < mpq[j] for all i < j
 * - used for sliding window min/max queries
 */

 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

struct min_queue {
	int sz = 0;
	deque<pi> q;
	min_queue() = default;
	min_queue(int sz) {
		this->sz = sz;
	}
	void insert(pi a) {
		while (!q.empty() && q.back().f >= a.f) {
			q.pop_back();
		}
		q.push_back(a);
	}
	int query(int i) {
		while (q.front().s < i - sz + 1) {
			q.pop_front();
		}
		return q.front().f;
	}
};

int n, m;
int a[MAXN];
int mini[MAXN];

int main() {
	setIO("input");
	cin >> n >> m;
	FOR (i, 0, n) {
		cin >> a[i];
	}
	min_queue mpq(m);
	FOR (i, 0, n) {
		mpq.insert(mp(a[i], i));
		mini[i] = mpq.query(i);
	}
	PRSP(i, n, mini);
}