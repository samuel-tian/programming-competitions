#include <bits/stdc++.h>

using namespace std;

#define MAXN 5000
#define endl '\n'

int n, k;
int steel[MAXN];
int dp[MAXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> steel[i];
    }
    fill(dp, dp + n, INT_MAX);
    dp[0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        double maxslope = -1 * (DBL_MAX - 1);
        for (int j = 1; j <= k && i + j < n; ++j) {
            double slope = (steel[i + j] - steel[i]) / ((double) j);
            if (slope >= maxslope) {
                maxslope = slope;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }
    cout << dp[n - 1] << endl;
}
