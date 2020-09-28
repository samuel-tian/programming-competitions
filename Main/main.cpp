#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

int n;
int arr[2*N];
int pos[2*N];
pair<int, int> inv[N];

void update(int i, int v) {
    i++;
    while (i <= 2*n) {
        arr[i] = arr[i] + v;
        i += i & (-i);
    }
}

int get(int i) {
    i++;
    int ret = 0;
    while (i > 0) {
        ret = ret + arr[i];
        i -= i & (-i);
    }
    return ret;
}

int query(int i, int j) {
    return get(j) - get(i-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        inv[i] = make_pair(-1, -1);
    }
    for (int i = 0; i < 2 * N; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < 2 * n; i++) {
        cin >> pos[i];
        pos[i]--;
        if (inv[pos[i]].first == -1)
            inv[pos[i]].first = i;
        else
            inv[pos[i]].second = i;
    }
    sort(inv, inv + n);
    long long ans = 0;
    for (int j = 0; j < n; j++) {
        ans += (long long)query(inv[j].first, inv[j].second);
        update(inv[j].second, 1);
    }
    cout << ans << '\n';
}
