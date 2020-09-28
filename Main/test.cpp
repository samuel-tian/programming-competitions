#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

int n;
int arr[2*N];
int pos[2*N], st_pos[N];
bool st[2*N], vis[N];

void update(int i, int v) {
    i++;
    while (i <= n) {
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
    for (int i = 0; i < 2 * n; i++) {
        cin >> pos[i];
        pos[i]--;
        vis[pos[i]] ^= 1;
        if (vis[pos[i]]) {
            st[i] = 1;
            st_pos[pos[i]] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << st_pos[i] << " " ;
        if (i == n-1)
            cout << '\n';
    }
    long long ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (st[i])
            update(i, 1);
        else {
            update(i, -1);
            cout << pos[i] << " " << query(st_pos[pos[i]], i) << '\n';
            ans += query(st_pos[pos[i]], i);
        }
    }
    cout << ans << '\n';
}
