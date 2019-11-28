#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 5000

int n;
char palin[MAXN];
int dp[MAXN][3];

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> palin[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[i][1] = 0;
    }
    for (int j = 2; j <= n; ++j) {
        for (int i = 0; i < n; ++i) {
            dp[i][j % 3] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (i + j - 1 >= n) continue;
            if (palin[i] == palin[i+j-1]) {
                dp[i][j % 3] = dp[i + 1][(j+1)%3];
            }
            else {
                dp[i][j%3] = 1 + min(dp[i][(j+2)%3], dp[i+1][(j+2)%3]);
            }
        }
//        for (int i = 0; i < n; ++i) {
//            cout << dp[i][j % 3] << " ";
//        }
//        cout << endl;
    }
    cout << dp[0][n % 3] << endl;
}