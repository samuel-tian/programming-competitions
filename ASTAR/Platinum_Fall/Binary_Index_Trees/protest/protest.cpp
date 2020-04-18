#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define MOD 1000000009LL

long long n;
long long signValues[MAXN];
long long psum[MAXN + 1];
long long tree[MAXN + 1];

void update(long long index, long long val) {
	index = index + 1;
	while (index <= n + 1) {
		tree[index] += val;
		index += index & (-index);
	}
}

long long get(long long index) {
	long long sum = 0;
	index = index + 1;
	while (index > 0) {
		sum += tree[index];
		index -= index & (-index);
	}
	return sum;
}

int main() {
//	freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	psum[0] = 0;
	for (long long i = 0; i < n; ++i) {
		cin >> signValues[i];
		psum[i + 1] = psum[i] + signValues[i];
	}
	sort(psum, psum + n + 1);
	update(lower_bound(psum, psum + n + 1, 0) - psum, 1);
	long long rsum = 0;
	long long inc;
	for (long long i = 0; i < n; ++i) {
//		for (long long i = 0; i <= n; ++i) {
//			cout << get(i) << " ";
//		}
//		cout << endl;
		rsum += signValues[i];
		inc = get(lower_bound(psum, psum + n + 1, rsum) - psum);
		update(lower_bound(psum, psum + n + 1, rsum) - psum, inc % MOD);
	}
//	for (long long i = 0; i <= n; ++i) {
//		cout << get(i) << " ";
//	}
//	cout << endl;
//	cout << get(n) - get(n - 1) << endl;
	cout << inc % MOD << endl;
//	cout << get(lower_bound(psum, psum + n + 1, rsum) - psum) << endl;
}
