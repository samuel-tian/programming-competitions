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

int main() {
	setIO("stdio");
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	pi a[n];
	FOR (i, 0, n) {
		a[i].f = (s[i] == 'R') ? 1 : 0;
	}
	int maxi = 0, mini = 0, last_delay = -1, dist = 1;
	int iter = 0;
	FOR (i, 0, n) {
		if (a[i].f == 0) {
			maxi += i - iter;
			a[i].s = iter;
			if (last_delay == -1) last_delay = 0;
			else {
				last_delay = last_delay + 2 - dist;
				if (last_delay < 0) last_delay = 0;
				mini = max(mini, last_delay + i - iter);
			}
			dist = 1;
			++iter;
		}
		else {
			++dist;
		}
	}
	if (k < mini || k > maxi) {
		cout << -1 << endl;
	}
	else {
		bool ones = false;
		vector<pi> st;
		while (k--) {
			if (!ones) {
				vi moves;
				FOR (i, 0, n-1) {
					if (a[i].f == 1 && a[i+1].f == 0) moves.pb(i);
				}
				if (maxi - moves.size() < k) {
					int sz = maxi - k;
					maxi = maxi - sz;
					cout << sz;
					FOR (i, 0, sz) {
						cout << " " << moves[i] + 1;
						pi temp = a[moves[i]];
						a[moves[i]] = a[moves[i]+1]; a[moves[i]+1] = temp;
					}
					cout << endl;
					ones = true;
					FORd (i, n-1, 0) {
						if (a[i].f == 0 && i > a[i].s) {
							st.push_back(mp(i, a[i].s));
						}
					}
				}
				else {
					maxi = maxi - moves.size();
					cout << moves.size();
					FOR (i, 0, moves.size()) {
						cout << " " << moves[i] + 1;
						pi temp = a[moves[i]];
						a[moves[i]] = a[moves[i]+1]; a[moves[i]+1] = temp;
					}
					cout << endl;
				}
			}
			else {
				/*FOR (i, 0, st.size()) {
					cout << "(" << st[i].f << " " << st[i].s << ") ";
				}
				cout << endl;*/
				cout << 1 << " " << st[st.size()-1].f << endl;
				st[st.size()-1].f--;
				if (st[st.size()-1].f == st[st.size()-1].s) st.pop_back();
			}
		}
	}
}