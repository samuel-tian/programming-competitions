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

int main() {
	setIO("stdio");
	int t;
	cin >> t;
	while (t--) {
		ll n, l, r;
		cin >> n >> l >> r;
		--l; --r;
		ll s[n];
		FOR (i, 0, n-1) {
			s[i] = 2*(n-i-1);
		}
		s[n-1] = 1;
//		PRSP(p, n);
//		PRSP(s, n);
		ll block = 0, iter;
		ll cnt = 0;
		while (cnt + s[block] <= l) {
			cnt += s[block++];
		}
		iter = l - cnt;
		for (ll iteration = l; iteration <= r; ++iteration) {
			if (block == n-1) {
				cout << 1 << " ";
				iter++;
			}
			else {
				if (iter % 2 == 0)  {
					cout << block + 1 << " ";
				}
				else {
					cout << block + iter / 2 + 2 << " ";
				}
				++iter;
				if (iter >= s[block]) {
					++block;
					iter = 0;
				}
			}
		}
		cout << endl;
	}
}
