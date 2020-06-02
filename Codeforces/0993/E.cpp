#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (auto& (i) : (x))
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
const double PI = 3.14159265358979323846264338327950;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

template <typename T>
struct Complex {
	T real, imag;
	Complex(T x=(T)0, T y=(T)0) : real(x), imag(y) {}
	Complex conj() { return Complex(real, -imag); }
	Complex operator + (const Complex& c) { return Complex(real + c.real, imag + c.imag); }
	Complex operator - (const Complex& c) { return Complex(real - c.real, imag - c.imag); }
	Complex operator * (const T& num) { return Complex(real * num, imag * num); }
	Complex operator / (const T& num) { return Complex(real / num, imag / num); }
	Complex operator * (const Complex& c) {
		return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
	}
	Complex operator/(const Complex& c) {
		return *this * c.conj() / (c.x * c.x + c.y * c.y);
	}
};

void fft(vector<Complex<long double> >& a, bool invert) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		Complex<long double> wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			Complex<long double> w(1);
			for (int j = 0; j < len / 2; ++j) {
				Complex<long double> u = a[i+j], v = a[i+j+len/2] * w;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
				w = w * wlen;
			}
		}
	}
	if (invert) {
		TRAV (x, a) {
			x = x / n;
		}
	}
}

vll poly_mul(vll &a, vll &b) {
	vector<Complex<long double> > fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size()) n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	FOR (i, 0, n) {
		fa[i] = fa[i] * fb[i];
	}
	fft(fa, true);
	vll ret(n);
	FOR (i, 0, n) ret[i] = (ll)round(fa[i].real);
	return ret;
}

vll poly_pow(vll& p, int k, const ll m) {
	if (k == 0) return {1};
	else if (k == 1) return p;
	vll q = poly_mul(p, p);
	TRAV (c, q) c %= m;
	q = poly_pow(q, k >> 1, m);
	if (k % 2) {
		q = poly_mul(q, p);
		TRAV (c, q) c %= m;
	}
	return q;
}

string poly_print(vi p) {
	string ret;
	bool leading = true;
	for (int i = p.size() - 1; i >= 0; i--) {
		if (!p[i]) continue;
		if (leading) ret += (p[i] < 0 ? "-" : "");
		else ret += (p[i] < 0 ? " - " : " + ");
		leading = false;
		if (abs(p[i]) != 1 || i == 0) ret += to_string(abs(p[i]));
		if (i) ret += (i == 1 ? "x" : "x^" + to_string(i));
	}
	return ret;
}

const int N = 200005;

int n, x;
vi a;
vi pre;
vll v, u;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> x;
    a.resize(N); pre.resize(N); v.resize(N);
    FOR (i, 0, n) cin >> a[i];
    ordered_set<int> s;
    FOR (i, 0, n) {
        s.insert(a[i]);
    }
    FOR (i, 0, n) {
        a[i] = s.order_of_key(a[i]);
    }
    x = s.order_of_key(x);
    FOR (i, 0, n) {
        pre[i+1] = pre[i] + (x > a[i]);
    }
    FOR (i, 0, n+1) {
        v[pre[i]]++;
    }
    u.resize(N);
    FOR (i, 0, n+1) {
        u[i] = v[n-i];
    }
    // PRSP(v, n+1);
    // PRSP(u, n+1);
    auto ret = poly_mul(u, v);
    FOR (i, n, 2*n+1) {
        if (i == n) {
            ll ans = 0;
            FOR (j, 0, n+1) {
                ans += ((u[j] * (u[j] - 1)) / 2);
            }
            cout << ans;
        }
        else {
            cout << " " << ret[i];
        }
    }
    cout << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

