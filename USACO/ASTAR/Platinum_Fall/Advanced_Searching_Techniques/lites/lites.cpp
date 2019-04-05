#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX

int n, m;
int tree[2*MAXN-1];
int lazy[2*MAXN-1];

void update(int cur, int l, int r, int ll, int rr) {
    if (lazy[cur] % 2 != 0) {
        tree[node] += 
    }
    if (r < ll || r > rr) {
        return 0;
    }
    else if (l >= ll && r <= rr) {
        tree
    }
}

int query(int l, int r)

int main() {
    cin >> n >> m;

}
