#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<ll, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (long long i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 505;
const int MAXK = 10005;
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
	ll c = 0;
	deque<pair<ll, int> > q;
	min_queue(pip store) {
		this->sz = store.s.f;
		this->c = store.s.s;
	}
	ll eval(pair<ll, int> a, int i) {
		return a.f + (i - a.s) * c;
	}
	void insert(pair<ll, int> a, ll i) {
		while (!q.empty() && eval(q.back(), i) >= a.f) {
			q.pop_back();
		}
		q.push_back(a);
	}
	ll query(ll i) {
		while (q.front().s < i - sz) {
			q.pop_front();
		}
		return eval(q.front(), i);
	}
	void display() {
		for (pi i : q) {
			printf("(%d, %d) ", i.f, i.s);
		}
		printf("\n");
	}
};

int k, e, n;
pair<ll, pair<ll, ll> > stores[MAXN];
ll dp[2][MAXK];

int main() {
	setIO("stdio");
	cin >> k >> e >> n;
	stores[0] = mpip(0, 0, 0);
	FOR (i, 1, n+1) {
		cin >> stores[i].f >> stores[i].s.f >> stores[i].s.s;
	}
	stores[n+1] = mpip(e, 0, 0);
	sort(stores, stores + n + 2);
//	FOR (i, 0, n+2) {
//		cout << stores[i].f << " " << stores[i].s.f << " " << stores[i].s.f << endl;
//	}
	FOR (i, 0, MAXN) {
		FOR (j, 0, MAXK) {
			dp[i % 2][j] = INF;
		}
	}
	dp[0][0] = 0;
	FOR (i, 1, n+2) {
		min_queue mpq(stores[i-1]);
//		printf("%d\n", i);
		FOR (j, 0, k+1) {
			mpq.insert(mp(dp[(i+1)%2][j], j), j);
			dp[i%2][j] = mpq.query(j);
			dp[i%2][j] += (stores[i].f - stores[i-1].f) * j * j;
//			printf("%d: ", j);
//			mpq.display();
		}
//		printf("\n");
	}
	/*FOR (i, 0, n+2) {
		FOR (j, 0, 5) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[(n+1)%2][k] << endl;
}