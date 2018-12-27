#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX

int n;
long long c;
long long a1, b1, d1;
long long a2, b2, d2;

int main() {
    scanf("%lld%lld", &c, &n);
    scanf("%lld%lld%lld", &a1, &b1, &d1);
    scanf("%lld%lld%lld", &a2, &b2, &d2);
    long long values[n];
    fill(values, values + n, 0);
    values[0] = c;
    int pf = 0, ps = 0;
    // cout << "a: " << a1 << " " << a2 << endl;
    // cout << "d: " << d1 << " " << d2 << endl;
    long long first = values[pf] * a1 / d1 + b1;
    long long second = values[ps] * a2 / d2 + b2;
    // cout << first << " " << second << endl;
    for (int i = 1; i < n; ++i) {
        if (first < second) {
            values[i] = first;
            first = values[++pf] * a1 / d1 + b1;
        }
        else {
            values[i] = second;
            second = values[++ps] * a2 / d2 + b2;
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << values[i] << " ";
    // }
    // cout << endl;
    cout << values[n - 1] << endl;
}
