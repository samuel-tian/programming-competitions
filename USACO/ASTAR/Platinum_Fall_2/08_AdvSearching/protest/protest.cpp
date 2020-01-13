#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define endl '\n'
#define MAXN 100000
#define MOD 1000000009

int n;
long long val[MAXN];
long long psum[MAXN + 1];
long long tree[MAXN + 1];

void update(long long index, long long val) {
    index = index + 1;
    while (index <= n + 1) {
        tree[index] += val;
        index += index & (-index);
    }
}

long long get(long long index) {
    long long sum = 0;
    index = index + 1;
    while (index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    psum[0] = 0;
    for (int i = 0; i < n; ++i) {
        psum[i + 1] = psum[i] + val[i];
    }
    sort(psum, psum + n + 1);
    update(lower_bound(psum, psum + n + 1, 0) - psum, 1);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += val[i - 1];
        /*for (int j = 0; j < n + 1; ++j) {
            cout << get(j) - get(j - 1) << " ";
        }
        cout << endl;*/
        long long transition = get(lower_bound(psum, psum + n + 1, sum) - psum) % MOD;
//        cout << transition << endl;
        update(lower_bound(psum, psum + n + 1, sum) - psum, transition);
        if (i == n) {
            /*for (int j = 0; j < n + 1; ++j) {
                cout << get(j) - get(j - 1) << " ";
            }
            cout << endl;*/
            cout << transition % MOD << endl;
        }
    }

}