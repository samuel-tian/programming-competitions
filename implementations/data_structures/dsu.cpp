#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par, r;
    DSU() = default;
	DSU(int n) {
		par.resize(n);
		r.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            r[i] = 0;
        }
	}
	int find(int i) {
		if (par[i] != i)
            par[i] = find(par[i]);
		return par[i];
	}
	bool same_set(int a, int b) {
		return find(a) == find(b);
	}
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (r[a] < r[b])
            swap(a, b);
		par[b] = a;
		r[a] = max(r[a], r[b] + 1);
	}
};

int main() {

}
