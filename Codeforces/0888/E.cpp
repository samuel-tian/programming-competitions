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

const int MAXN = 35;

int n, m;
int a[MAXN];
vi first_sum, second_sum;

void compute(int cur, int tot, int stop) {
	if (cur >= stop) {
		if (stop == n) {
			second_sum.pb(tot);
		}
		else {
			first_sum.pb(tot);
		}
		return;
	}
	compute(cur + 1, tot, stop);
	compute(cur + 1, (tot + a[cur]) % m, stop);
}

int lower(vi &v, int x) {
	int lo = 0, hi = v.size() - 1;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (v[mid] > x) {
			hi = mid - 1;
		}
		else {
			lo = mid;
		}
	}
	return v[lo];
}

int main() {
	setIO("stdio");
	cin >> n >> m;
	FOR (i, 0, n) {
		cin >> a[i];
		a[i] = a[i] % m;
	}
	compute(0, 0, n/2 + 1);
	compute(n/2 + 1, 0, n);
	first_sum.pb(0);
	second_sum.pb(0);
	int ret = 0;
	sort(first_sum.begin(), first_sum.end());
	sort(second_sum.begin(), second_sum.end());
//	PRSP(first_sum, first_sum.size());
//	PRSP(second_sum, second_sum.size());
	FOR (i, 0, first_sum.size()) {
		ret = max(ret, (first_sum[i] + second_sum[second_sum.size() - 1]) % m);
		int pos = lower(second_sum, m - 1 - first_sum[i]);
//		if (first_sum[i] == 208) cout << pos << endl;
		ret = max(ret, (first_sum[i] + pos) % m);
	}
	cout << ret << endl;
}
