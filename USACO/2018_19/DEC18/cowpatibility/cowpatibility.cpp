#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 50000

struct Subset {
	long long flavors[5] {0, 0, 0, 0, 0};
};

bool operator < (const Subset& a, const Subset& b) {
	for (long long i = 0; i < 5; ++i) {
		if (a.flavors[i] < b.flavors[i]) return true;
		else if (a.flavors[i] > b.flavors[i]) return false;
	}
	return false;
}

long long n;
Subset favorites[MAXN];
map<Subset, long long> commonSubsets;

Subset generateSubsets(long long s, long long x) {
	Subset ret;
	long long counter = 0;
	for (long long i = 0; i < 5; ++i) {
		if ((1 << i) & x) {
//			cout << "PASS" << endl;
			ret.flavors[counter] = favorites[s].flavors[i];
			++counter;
		}
	}
//	if (x == 3) {
//		for (long long i = 0; i < 5; ++i) {
//			cout << ret.flavors[i] << " ";
//		}
//		cout << endl;
//	}

	return ret;
}

int main() {
//	freopen("input.txt", "r", stdin);
	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);
	cin >> n;
	for (long long i = 0; i < n; ++i) {
		for (long long j = 0; j < 5; ++j) {
			cin >> favorites[i].flavors[j];
		}
		sort(favorites[i].flavors, favorites[i].flavors + 5);
		for (long long j = 1; j <= 31; ++j) {
			Subset s = generateSubsets(i, j);
//			long long size = 0;
//			while (size < 5 && s.flavors[size] != 0) ++size;
//			for (long long k = 0; k < size; ++k) {
//				cout << s.flavors[size] << " ";
//			}
//			cout << endl;
			++commonSubsets[s];
		}
	}

	long long total = 0;
	for (auto s : commonSubsets) {
		long long size = 0;
		while (size < 5 && s.first.flavors[size] != 0) ++size;
		if (size == 0) continue;
//		cout << "set: ";
//		for (long long i = 0; i < size; ++i) {
//			cout << s.first.flavors[i] << " ";
//		}
//		cout << endl << s.second << endl;
		total += (s.second * (s.second - 1)) / 2 * (size % 2 == 0 ? -1 : 1);
	}
//	cout << total << endl;
	cout << (n * (n - 1)) / 2 - total << endl;
	return 0;
}
