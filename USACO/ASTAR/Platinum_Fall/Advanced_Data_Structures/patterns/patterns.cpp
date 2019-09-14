#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 20000
#define INF 1000003
#define PRIME 11

int n, k;
int samples[MAXN];

struct Hash {
	long long hashval;
	int sbegin, send;
};

struct Compare {
	bool operator() (const Hash &a, const Hash &b) const {
		if (a.hashval == b.hashval) {
			for (int i = 0; i < a.send - a.sbegin + 1; ++i) {
				if (samples[a.sbegin + i] != samples[b.sbegin + i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
};

struct HashExtract {
	long long operator() (const Hash &a) const {
		return a.hashval;
	}
};

int main() {
//	freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> samples[i];
	}
	int low = 1, high = n;
	while (low + 1 < high) {
		int l = (low + high) / 2;
		unordered_map<Hash, long long, HashExtract, Compare> hmap;
		Hash startingHash = {0, 0, l - 1};
		long long power = 1;
		for (int i = 0; i < l; ++i) {
			startingHash.hashval = (startingHash.hashval * PRIME + samples[i]) % INF;
			if (i >= 1) {
				power = (power * PRIME) % INF;
			}
		}
		hmap[startingHash]++;
		bool flag = false;
		for (int i = 0; i + l < n; ++i) {
			startingHash.hashval = (PRIME * (startingHash.hashval - power * samples[i]) + samples[i + l]) % INF;
			startingHash.sbegin += 1;
			startingHash.send += 1;
			if (++hmap[startingHash] >= k) {
				flag = true;
				break;
			}
		}
		if (flag) low = l;
		else high = l;
	}
	cout << low << endl;
}
