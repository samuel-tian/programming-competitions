#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j < i) continue;
            for (int k = 0; k < 5; k++) {
                if (k >= i && k <= j)
                    ans++;
            }
        }
    }
    cout << ans << '\n';
}
