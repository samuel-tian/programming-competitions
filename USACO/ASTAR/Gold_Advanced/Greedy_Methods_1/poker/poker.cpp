/*input
5
2
4
1
2
3
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 100000
#define endl '\n'
#define INF INT_MAX

int main() {
	int n;
	cin >> n;
	int cards[n + 2];
	cards[0] = cards[n + 1] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> cards[i + 1];
	}
	long long ans = 0;
	for (int i = 0; i < n + 1; ++i) {
		ans += abs(cards[i + 1] - cards[i]);
	}
	ans = ans / 2LL;
	cout << ans << endl;
}
