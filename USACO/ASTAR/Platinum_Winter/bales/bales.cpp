#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 1000000

int main() {
    int n, q;
    cin >> n >> q;
    int haybales[n];
    fill(haybales, haybales + n, INF);
    for (int i = 1; i <= q; ++i) {
        int start, finish, value;
        cin >> start >> finish >> value;
        for (int j = start - 1; j <= finish - 1; ++j) {
            if (value > haybales[j]) {
                cout << j
            }
        }
    }
}
