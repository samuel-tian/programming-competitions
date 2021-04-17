#include <bits/stdc++.h>

using namespace std;

/*
 * decreasing slopes, decreasing query positions
 * slopes = insert
 * queries = query
 */
struct CHT {
    struct Line {
        long long m, b;
        long long eval(long long x) {
            return this->m * x + this->b;
        }
        long double intersect(Line l) {
            return (long double) (b - l.b) / (l.m - m);
        }
    };
    deque<Line> dq;
    long long query(long long x) {
        while (dq.size() >= 2 && dq[dq.size()-1].eval(x) <= dq[dq.size()-2].eval(x)) {
            dq.pop_back();
        }
        return dq.back().eval(x);
    }
    void insert(Line l) {
        while (dq.size()>=2 && l.intersect(dq[0]) >= dq[0].intersect(dq[1])) {
            dq.pop_front();
        }
        dq.push_front(l);
    }
};

int main() {

}
