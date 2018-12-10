/*input
5 5
10
40
13
22
7
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAXN 50000

int n, d;
int chocolates[MAXN];

bool possible(long long minHappiness) {
	long long currentHappiness = 0;
	int currentChocolate = 0;
	for (int i = 0; i < d; ++i) {
		while (currentChocolate < n && currentHappiness < minHappiness) {
			currentHappiness += chocolates[currentChocolate];
			// cout << "day " << i << ": " << currentChocolate << endl;
			++currentChocolate;
		}
		if (currentHappiness < minHappiness) return false;
		currentHappiness /= 2;
	}
	return true;
}

void dayEaten(long long minHappiness) {
	long long currentHappiness = 0;
	int currentChocolate = 0;
	for (int i = 0; i < d; ++i) {
		while (currentHappiness < minHappiness) {
			currentHappiness += chocolates[currentChocolate];
			cout << i + 1 << endl;
			++currentChocolate;
		}
		currentHappiness /= 2;
	}
	for (int i = currentChocolate; i < n; ++i) {
		cout << d << endl;
	}
}

long long recurse(long long l, long long h) {
	if (l == h) return l;
	// cout << l << " " << h;
	long long m = (l + h + 1L) / 2;
	if (possible(m)) {
		// cout << " possible" << endl;
		return recurse(m, h);
	}
	else {
		// cout << " not possible" << endl;
		return recurse(l, m - 1);
	}
}

int main() {
	cin >> n >> d;
	long long total = 0;
	for (int i = 0; i < n; ++i) {
		cin >> chocolates[i];
		total += chocolates[i];
	}
	long long ans = recurse(0, total);
	cout << ans << endl;
	dayEaten(ans);
}