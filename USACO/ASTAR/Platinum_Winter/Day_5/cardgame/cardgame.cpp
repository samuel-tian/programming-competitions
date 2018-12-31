#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50000

int n;
bool card[MAXN*2];
vector<int> bessie, elsie;
set<int> bessiehigh, bessielow;
int highcard[MAXN+1], lowcard[MAXN+1];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		card[a-1] = true;
		elsie.push_back(a-1);
	}
	for (int i = 0; i < 2*n; ++i) {
		if (!card[i]) {
			bessie.push_back(i);
			bessiehigh.insert(i);
			bessielow.insert(i);
		}
	}
	highcard[0] = 0;
	// for (auto it = bessiehigh.begin(); it != bessiehigh.end(); ++it) {
	// 	cout << *it << " ";
	// }
	// cout << endl;
	for (int i = 1; i <= n; ++i) {
		auto iter = bessiehigh.lower_bound(elsie[i-1]);
		if (iter != bessiehigh.end()) {
			highcard[i] = highcard[i-1]+1;
			bessiehigh.erase(iter);
		}
		else {
			highcard[i] = highcard[i-1];
			bessiehigh.erase(bessiehigh.begin());
		}
		// for (auto it = bessiehigh.begin(); it != bessiehigh.end(); ++it) {
		// 	cout << *it << " ";
		// }
		// cout << endl;
	}
	lowcard[n] = 0;
	// for (auto it = bessielow.begin(); it != bessielow.end(); ++it) {
	// 	cout << *it << " ";
	// }
	// cout << endl;
	for (int i = n-1; i >= 0; --i) {
		auto iter = bessielow.upper_bound(elsie[i]);
		// cout << "ITER: " << *iter << endl;
		if (iter != bessielow.begin()) {
			lowcard[i] = lowcard[i+1]+1;
			bessielow.erase(prev(iter));
		}
		else {
			lowcard[i] = lowcard[i+1];
			bessielow.erase(prev(bessielow.end()));
		}
		// for (auto it = bessielow.begin(); it != bessielow.end(); ++it) {
		// 	cout << *it << " ";
		// }
		// cout << endl;
	}
	// for (int i = 0; i <= n; ++i) {
	// 	cout << lowcard[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i <= n; ++i) {
	// 	cout << highcard[i] << " ";
	// }
	// cout << endl;
	int ret = 0;
	for (int i = 0; i <= n; ++i) {
		ret = max(ret, lowcard[i]+highcard[i]);
	}
	cout << ret << endl;
	return 0;
}
