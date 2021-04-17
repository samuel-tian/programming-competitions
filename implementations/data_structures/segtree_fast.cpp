#include <bits/stdc++.h>

using namespace std;

const int N = 500005;
const int Q = 500005;

template<class T>
struct segtree {
    int n;
    vector<T> t;
    segtree() = default;
    segtree(int n) {
        this->n = n;
        int sz = 2*n;
        t.resize(sz);
    }
    T comb(T l, T r) {
        return l + r;
    }
    void set(int i, T v) {
        t[i + n] = v;
    }
    void build() {
        for (int i = n-1; i >= 1; i--) {
            t[i] = comb(t[i<<1], t[i<<1|1]);
        }
    }
    void update(int p, T v) {
        p += n;
        t[p] += v;
        while (p != 1) {
            p >>= 1;
            t[p] = comb(t[p<<1], t[p<<1|1]);
        }
    }
    T query(int l, int r) {
        T resl = 0, resr = 0;
        l += n, r += n+1;
        while (l < r) {
            if (l & 1) resl = comb(resl, t[l++]);
            if (r & 1) resr = comb(t[--r], resr);
            l >>= 1, r >>= 1;
        }
        return comb(resl, resr);
    }
};

int main() {

}

