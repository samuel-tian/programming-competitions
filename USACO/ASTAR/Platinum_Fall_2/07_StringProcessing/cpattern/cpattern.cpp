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

const int MAXN = 100005;
const int MAXK = 25005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const int INV = 139979861;

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

int n, k, s;
int cows[MAXN];
int pattern[MAXK];
ll sequence_hash[25][MAXN];
ll pattern_hash[25];

ll mod_pow(int exp) {
	if (exp == 0) return 1;
	else if (exp == 1) return MUL;
	else {
		ll t = mod_pow(exp / 2);
		ll ret = (t * t) % MOD;
		return (exp % 2 == 1) ? (ret*MUL)%MOD : ret;
	}
}

void hash_pattern() {
	int counter[25], cc[25];
	fill(counter, counter + 25, 0);
	FOR (i, 0, k) {
		counter[pattern[i] - 1]++;
	}
	int iter = 0;
	FOR (i, 0, 25) {
		if (counter[i] == 0) cc[i] = -1;
		else cc[i] = iter++;
	}
	FOR (i, 0, k) {
		pattern[i] = cc[pattern[i]-1];
	}
	bool barry[25][k];
	FOR (i, 0, 25) {
		FOR (j, 0, k) {
			barry[i][j] = false;
		}
	}
	FOR (i, 0, k) {
		barry[pattern[i]][i] = true;
	}
	FOR (i, 0, 25) {
		FOR (j, 0, k) {
			pattern_hash[i] = (pattern_hash[i] * MUL + barry[i][j]) % MOD;
		}
	}
}

void rolling_hash() {
	bool barry[25][n];
	FOR (i, 0, 25) {
		FOR (j, 0, n) {
			barry[i][j] = false;
		}
	}
	FOR (i, 0, n) {
		barry[cows[i]][i] = true;
	}
	ll power = mod_pow(k-1);
	FOR (i, 0, s) {
		FOR (j, 0, k) {
			sequence_hash[i][0] = (sequence_hash[i][0] * MUL + barry[i][j]) % MOD;
		}
		FOR (j, k, n) {
			sequence_hash[i][j-k+1] = ((sequence_hash[i][j-k] - power * barry[i][j-k]) * MUL + barry[i][j]) % MOD;
			if (sequence_hash[i][j-k+1] < 0) sequence_hash[i][j-k+1] += MOD;
		}
	}
}

int main() {
	setIO("stdio");
	cin >> n >> k >> s;
	FOR (i, 0, n) {
		cin >> cows[i];
		--cows[i];
	}
	FOR (i, 0, k) {
		cin >> pattern[i];
	}
	hash_pattern();
	rolling_hash();
	/*FOR (i, 0, 25) {
		cout << pattern_hash[i] << endl;
	}
	FOR (i, 0, 25) {
		FOR (j, 0, n-k+1) {
			cout << sequence_hash[i][j] << " ";
		}
		cout << endl;
	}*/
	int counter[25], cc[25];
	fill(counter, counter + 25, 0);
	fill(cc, cc + 25, -1);
	vi matches;
	FOR (i, 0, n-k+1) {
		if (i == 0) {
			FOR (j, 0, k) {
				counter[cows[j]]++;
			}
		}
		else {
			counter[cows[i-1]]--;
			counter[cows[i+k-1]]++;
		}
		int iter = 0;
		FOR (j, 0, 25) {
			if (counter[j] == 0) cc[j] = -1;
			else cc[j] = iter++;
		}
//		PRSP(j, 25, counter);
//		PRSP(j, 25, cc);
		FOR (j, 0, 26) {
			if (j == 25) {
				matches.pb(i);
				break;
			}
			if (cc[j] == -1) continue;
			if (sequence_hash[j][i] != pattern_hash[cc[j]]) break;
		}
	}
	cout << matches.size() << endl;
	for (int i : matches) {
		cout << i + 1<< endl;
	}
}