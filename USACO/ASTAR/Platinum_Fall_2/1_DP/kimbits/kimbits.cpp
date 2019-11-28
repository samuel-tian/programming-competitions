#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 31

long long N, L, I;
int dp[MAXN + 1][MAXN + 1];
// first is the length of the string
// second is the most number of 1s in the bistring

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> N >> L >> I;
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= L; ++i) {
        dp[0][i] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= L; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    string ans;
    int popcount = 0;
    long long index = 0;
    /*for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= L; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    for (int i = 0; i < N; ++i) {
        if (index + dp[N-(i+1)][L-(popcount)] < I) {
            index += dp[N-(i+1)][L-popcount];
            ans += "1";
            ++popcount;
//            cout << I << endl;
        }
        else {
            ans += "0";
        }
    }
    cout << ans << endl;
    /*
     * 1 00000
     * 2 00001
     * 3 00010
     * 4 00011
     * 5 00100
     * 6 00101
     * 7 00110
     * 8 00111
     * 9 01000
     * 10 01001
     * 11 01010
     * 12 01011
     * 13 01100
     * 14 01101
     * 15 01110
     * 16 10000
     * 17 10001
     * 18 10010
     * 19 10011
     * 20 10100
     * 21 10101
     * 22 10110
     * 23 11000
     * 24 11001
     * 25 11010
     * 26 11100
     */
}