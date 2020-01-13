#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 20

int n;
int s[MAXN];
int sum;
bool dp[2][1000][667];

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sum += s[i];
    }
    dp[0][0][0] = true;
    for (int j = 1; j <= n; ++j) {
        for (int a = 0; a < 1000; ++a) {
            for (int b = 0; b < 667; ++b) {
                dp[j%2][a][b] = false;
            }
        }
        for (int a = 0; a < 1000; ++a) {
            for (int b = 0; b < 667; ++b) {
                if (dp[(j+1)%2][a][b]) {
                    dp[j%2][a][b] = true;
                    if (a+s[j-1] < 1000)
                        dp[j%2][a+s[j-1]][b] = true;
                    if (b+s[j-1] < 667)
                        dp[j%2][a][b+s[j-1]] = true;
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 667; ++j) {
            if (dp[n%2][i][j]) {
                ans = min(ans, max(max(i, j), sum - i - j));
            }
        }
    }
    cout << ans << endl;
}