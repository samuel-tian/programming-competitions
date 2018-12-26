#include <iostream>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 2000
#define MAXF 1000

int n, f;
int skills[MAXN];
int dp[MAXN + 1][MAXF];
// dp[i][j] stores the number of ways to form teams whose sum is congruent to j mod f
// using the first i cows

int main() {
    cin >> n >> f;
    for (int i = 0; i < n; ++i) {
        cin >> skills[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < f; ++j) {
            if (dp[i][j] == 0) {
                continue;
            }
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % 100000000;
            dp[i + 1][(j + skills[i]) % f] = (dp[i + 1][(j + skills[i]) % f] + dp[i][j]) % 100000000;
        }
    }
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j < f; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][0] - 1 << endl;
}
