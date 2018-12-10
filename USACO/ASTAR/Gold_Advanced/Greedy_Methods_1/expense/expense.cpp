/*input
7 5
100
400
300
100
500
101
400
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100000

int n, m;
int minSpending = INF;
int money[MAXN];

bool possible(int spending) {
	int fajomonths = 1;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		if (money[i] > spending) return false;
		if (total + money[i] <= spending)
			total += money[i];
		else {
			--i;
			total = 0;
			++fajomonths;
		}
	}
	return (fajomonths <= m);
}

void binarySearch(int low, int high) {
	int val = (low + high) / 2;
	if (low > high) return;
	if (possible(val)) {
		minSpending = min(minSpending, val);
		binarySearch(low, val - 1);
	}
	else
		binarySearch(val + 1, high);
}

int main() {
	cin >> n >> m;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		cin >> money[i];
		total += money[i];
	}
	binarySearch(0, total);
	cout << minSpending << endl;
}