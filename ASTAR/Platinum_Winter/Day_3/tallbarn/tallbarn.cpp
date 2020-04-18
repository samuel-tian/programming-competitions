#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAXN 100000

long long k, n;
long long val[MAXN];

long long count(double mid) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += (long long)((sqrt(1+4*val[i]/mid)-1)/2);
	}
	return ret >= k;
}

int main() {
	cin >> n >> k;
	k -= n;
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	double lo = 0, hi = 1e12;
	for (int i = 0; i < 200; ++i) {
		double mid = (lo + hi) / 2;
		if (count(mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	double ans = 0;
	long long total = 0;
	for (int i = 0; i < n; ++i) {
		long long cows = (long long)((sqrt(1+4.0*val[i]/lo)-1)/2);
		ans += (double)(val[i])/(cows+1);
		total += cows;
	}
	cout << (long long) round(ans-(k-total)*lo) << endl;
}
