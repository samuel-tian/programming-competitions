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
const int MAXK = 35;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const ll MUL = 10000001;
const ll MOD = 100000000007;

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

int n, k;
int s[MAXN][MAXK];
int a[MAXN][MAXK];

int main() {
	setIO("stdio");
	cin >> n >> k;
	FOR (i, 0, k) {
		s[0][i] = 0;
	}
	FOR (i, 1, n+1) {
		int a;
		cin >> a;
		for (int iter = 0, j = 1; iter < k; ++iter, j = j * 2) {
			s[i][iter] = s[i-1][iter] + (((a & j) != 0) ? 1 : 0);
//			cout << (a & j) << " ";
		}
//		cout << endl;
	}
	FOR (i, 0, n+1) {
		FOR (j, 0, k-1) {
			a[i][j] = s[i][j] - s[i][j+1];
		}
	}
	/*FOR (j, 0, k) {
		FOR (i, 0, 20) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}*/
	unordered_map<ll, pi> m;
	FOR (i, 0, n+1) {
		ll h = 0;
		FOR (j, 0, k-1) {
			h = (h * MUL + a[i][j]) % MOD;
		}
		if (m.find(h) != m.end()) {
			pi t = m[h];
			m[h] = mp(min(t.f, i), max(t.s, i));
		}
		else {
			m[h] = mp(i, i);
		}
	}
	int ret = 0;
	for (pair<ll, pi> i : m) {
		/*if (i.s.s - i.s.f > 0) {
			printf("(%d, %d) %d\n", i.s.f, i.s.s, i.s.s - i.s.f);
		}*/
		ret = max(ret, i.s.s - i.s.f);
//		printf("(%d, %d)\n", i.s.f, i.s.s);
	}
	cout << ret << endl;
}