#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (int (i) : (x))
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c))
#define min3(a, b, c) min(min((a), (b)), (c))

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "") return;
	if (name == "input") {freopen("input.txt","r",stdin);}
	else {freopen((name+".in").c_str(),"r",stdin); freopen((name+".out").c_str(),"w",stdout);}
}

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

int main() {
	setIO();
	/*int n = 500;
	bool used[10000];
	bitset<8> x;
	FOR (i, 0, 10000) used[i] = false;
	int iter = 1;
	FOR (iteration, 0, 67) {
		while (used[iter]) ++iter;
		used[iter] = true;
		cout << iter << " ";
		FOR (i, 0, 10000) {
			if (used[i] || used[i ^ iter] || i==(i^iter)) continue;
			used[i] = true;
			used[i ^ iter] = true;
			cout << i << " " << (i^iter) << endl;
			x = bitset<8>(iter); cout << x << " ";
			x = bitset<8>(i); cout << x << " ";
			x = bitset<8>(i^iter); cout << x << endl;
			break;
		}
	}*/
	int t;
	cin >> t;
	bool a_bit[][4] = {{0, 1, 0, 1}, {0, 0, 1, 1}};
	bool b_bit[][4] = {{0, 0, 1, 1}, {0, 1, 1, 0}};
	while (t--) {
		ull n;
		cin >> n;
		n--;
		ull line = n/3, pos = n%3;
		ull blk = 0;
		ull iter = 0, mul = 0;
		while ((pow(4, mul+1)-1)/3 <= line) {
			iter = ((ull)pow(4, mul+1)-1)/3; mul++; blk++;
		}
		bitset<64> aset(0), bset(0);
//		cerr << line << " " << mul << " " << blk << endl;
		aset.set(2*mul); bset.set(2*mul+1);
		line = line - iter;
		FOR (i, 0, mul) {
			aset.set(2*i, a_bit[0][line%4]);
			aset.set(2*i+1, a_bit[1][line%4]);
			bset.set(2*i, b_bit[0][line%4]);
			bset.set(2*i+1, b_bit[1][line%4]);
			line /= 4;
		}
		ull a = aset.to_ullong();
		ull b = bset.to_ullong();
		ull c = a ^ b;
		switch (pos) {
			case 0: cout << a << endl; break;
			case 1: cout << b << endl; break;
			case 2: cout << c << endl; break;
		}
	}
}
