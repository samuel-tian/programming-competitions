#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
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
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	if (name == "")
        return;
    if (name == "input") {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
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
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(ll x) const {
        return x ^ RANDOM;
    }
};

template<typename T>
struct BIT {
    int n;
    vector<T> arr1, arr2, arr3;
    vector<T> arr4;
    BIT() = default;
    BIT(int n) {
        resize(n);
    }
    void resize(int n) {
        this->n = n;
        arr1.resize(n+1);
        arr2.resize(n+1);
        arr3.resize(n+1);
        arr4.resize(n+1);
    }
    void clear() {
        this->n = 0;
        arr1.clear();
        arr2.clear();
        arr3.clear();
        arr4.clear();
    }
    void set(int i, T v) {
        update_util(arr4, i, v);
    }
	void update_util(vector<T>& arr, int i, T v) {
        i++;
		while (i <= n) {
			arr[i] = arr[i] + v;
			i += i & (-i);
		}
	}
    void update(long long l, long long r) {
        update_util(arr1, l, 1);
        update_util(arr1, r+1, -1);
        update_util(arr2, l, 3-2*l);
        update_util(arr2, r+1, 2*l-3);
        update_util(arr3, l, (l-1) * (l-2));
        update_util(arr3, r+1, r*r - r*(2*l-3));
    }
	T get_util(vector<T>& arr, int i) {
		T ret = 0;
        i++;
		while (i > 0) {
			ret = ret + arr[i];
			i -= i & (-i);
		}
		return ret;
	}
    T get(long long i) {
        return get_util(arr4, i) + (i*i*get_util(arr1, i) + i*get_util(arr2, i) + get_util(arr3, i)) / 2;
    }
	T query(long long i, long long j) {
        return get(j) - get(i-1);
    }
};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    int n, q;
    cin >> n >> q;
    BIT<long long> bit(n);
    FOR (i, 0, n) {
        int a;
        cin >> a;
        bit.set(i, a);
    }
    FOR (i, 0, q) {
        int type;
        cin >> type;
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (type==1)
            bit.update(a, b);
        else
            cout << bit.query(a, b) << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

