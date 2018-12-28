#include <iostream>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX
#define PI 3.14159265358979323846

int n;
pair<int, int> cows[MAXN];
double angles[MAXN];

#define inc(a) (a + 1) % n
#define dif(a, b) a-b<=0?a-b+360:a-b

double atan(int x, int y) {
    double angle = 180 / PI * atan2(y, x);
    if (angle < 0) {
        return 360 + angle;
    }
    return angle;
}

long long choose(int n, int k) {
    long long ans = 1;
    for (int i = n; i >= n - k + 1; --i) {
        ans *= i;
    }
    for (int i = 1; i <= k; ++i) {
        ans /= i;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
        angles[i] = atan(cows[i].first, cows[i].second);
    }
    sort(angles, angles + n);
    // for (int i = 0; i < n; ++i) {
    //     cout << angles[i] << " ";
    // }
    // cout << endl;
    int pt = 0;
    long long ans = 0;
    // cout << "DIF: " << angles[0] - angles[2] << " " << (dif(angles[0], angles[2])) << endl;
    for (int i = 0; i < n; ++i) {
        while ((dif(angles[inc(pt)], angles[i])) < 180) {
            // cout << "difference: " << i << " " << inc(pt) << " " << (dif(angles[inc(pt)], angles[i])) << endl;
            pt = inc(pt);
            // cout << pt << endl;
        }
        // cout << "i: " << i << " pt: " << pt << endl;
        if (pt == i) continue;
        ans += choose((pt - i + n) % n, 2);
    }
    cout << choose(n, 3) - ans << endl;
}
