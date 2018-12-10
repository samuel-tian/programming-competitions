#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAXN 10

int n, k;
int sequence[MAXN];

int choose(int n, int k) {
	int product = 1;
	for (int i = n; i >= n - k + 1; --i) {
		product *= i;
	}
	for (int i = 1; i <= k; ++i) {
		product /= i;
	}
	return product;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		sequence[i] = i + 1;
	}
	do {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += choose(n - 1, i) * sequence[i];
		}
		if (sum == k) {
			cout << sequence[0];
			for (int i = 1; i < n; ++i) {
				cout << " " << sequence[i];
			}
			cout << endl;
			break;
		}
	} while (next_permutation(sequence, sequence + n));
}