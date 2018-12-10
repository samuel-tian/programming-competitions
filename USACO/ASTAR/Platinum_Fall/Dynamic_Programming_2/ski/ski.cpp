/*input
10 1 2
3 2 5
4 1
1 3
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAXT 10000
#define MAXS 10000
#define MAXN 10000
#define MAXA 100

struct lessons {
	int start;
	int length;
	int skill;
};

struct slopes {
	int time;
	int skill;
};

int main() {
	int t, s, n;
	cin >> t >> s >> n;
	lessons lesson[MAXS];
	slopes slope[MAXN];
	int dp[MAXT + 1][MAXA];
	for (int i = 0; i < s; ++i) {
		cin >> lesson[i].start >> lesson[i].length >> lesson[i].skill;
	}
	for (int i = 0; i < n; ++i) {
		cin >> slope[i].time >> slope[i].skill;
	}
	dp[0] = 0;
	for (int i = 1; i <= t; ++i) {

	}
}