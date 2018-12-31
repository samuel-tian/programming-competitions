#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 4000000

int n;
long long c;
long long a1, b1, d1;
long long a2, b2, d2;
long long values[MAXN+1];

int main() {
	cin >> c >> n;
	cin >> a1 >> b1 >> d1;
	cin >> a2 >> b2 >> d2;
	memset(values, 0, sizeof(values));
    values[0] = c;
    int pf = 0, ps = 0;
    // cout << "a: " << a1 << " " << a2 << endl;
    // cout << "d: " << d1 << " " << d2 << endl;
    long long first = values[pf] * a1 / d1 + b1;
    long long second = values[ps] * a2 / d2 + b2;
    // cout << first << " " << second << endl;
	int i = 1;
    while (i < n) {
        if (first < second) {
			if (first != values[i - 1]) {
				values[i] = first;
				++i;
			}
            first = values[++pf] * a1 / d1 + b1;
        }
        else {
			if (second != values[i - 1]) {
				values[i] = second;
				++i;
			}
            second = values[++ps] * a2 / d2 + b2;
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << values[i] << " ";
    // }
    // cout << endl;
    cout << values[n - 1] << endl;
}
