#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int Q = 200005;

int n, q;
int x[N];
pair<int, int> qry[Q];
int lef[N], rig[N], ans[Q];

void solve(int l, int r, vector<int> v) {
    if (v.empty())
        return;
    if (l == r) {
        for (int i : v)
            ans[i] = x[l];
        return;
    }
    int mid = (l + r) / 2;
    lef[mid] = x[mid];
    rig[mid+1] = x[mid+1];
    for (int i = mid-1; i >= l; i--)
        lef[i] = min(x[i], lef[i+1]);
    for (int i = mid+2; i <= r; i++)
        rig[i] = min(x[i], rig[i-1]);
    vector<int> todo[2];
    for (int i : v) {
        int a = qry[i].first, b = qry[i].second;
        if (a <= mid && mid < b)
            ans[i] = min(lef[a], rig[b]);
        else {
            if (a > mid)
                todo[1].push_back(i);
            else
                todo[0].push_back(i);
        }
    }
    solve(l, mid, todo[0]);
    solve(mid+1, r, todo[1]);
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<int> v;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        qry[i] = {a, b};
        v.push_back(i);
    }
    solve(0, n-1, v);
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}
