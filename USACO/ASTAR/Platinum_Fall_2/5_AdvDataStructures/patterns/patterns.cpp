#include <bits/stdc++.h>

using namespace std;

#define INF LONG_LONG_MAX
#define endl '\n'
#define MAXN 20000

#define MOD 1000000007
#define EXP 1000001
#define INV 139979861

long long n, k;
long long pattern[MAXN];

long long modPow(long long exponent) {
	if (exponent == 0) {
		return 1;
	}
	else if (exponent == 1) {
		return EXP;
	}
	else {
		long long temp = modPow(exponent / 2);
		long long ret = (temp * temp) % MOD;
		if (exponent % 2 == 1) ret = (ret * EXP) % MOD;
		return ret;
	}
}

long long rollingHash(long long length) {
	std::map<long long, long long> count;
	long long hash = 0;
	long long power = modPow(length - 1);
	for (long long i = length - 1; i >= 0; --i) {
		hash = (hash * EXP + pattern[i]) % MOD;
	}
	count[hash]++;
	for (long long i = length; i < n; ++i) {
		hash = ((INV * (hash - pattern[i - length])) % MOD + (pattern[i] * power) % MOD) % MOD;
		count[hash]++;
	}
	long long ret = -1;
	for (pair<long long, long long> i : count) {
		ret = max(ret, i.second);
	}
	return ret;
}

int main() {
	cin >> n >> k;
	for (long long i = 0; i < n; ++i) {
		cin >> pattern[i];
	}
	long long lo = 0;
	long long hi = n - 1;
	while (lo < hi) {
		long long mid = (lo + hi + 1) / 2;
		if (rollingHash(mid) >= k) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << lo << endl;
}
