/*
 * Inversion Counting
 * ------------------
 * given an array, count the pairs i, j such that i<j and a[i]>a[j]
 * 1) initialize a BIT ranging from 0 to the maximum value that the array contains
 * 2) iterate through the array backwards
 *      a) calculate the prefix sum of a[i]
 *      b) increment the value of a[i] by 1
 * time complexity: O(n log MAX)
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define MAXN 100000
#define MAX 100000
#define endl '\n'

int n;
int a[MAXN];
int fenwick[MAX+1];

void insert(int index, int val) {
    ++index;
    while (index <= MAX) {
        fenwick[index] += val;
        index += index & (-index);
    }
}

int get(int index) {
    int ret = 0;
    ++index;
    while (index > 0) {
        ret += fenwick[index];
        index -= index & (-index);
    }
    return ret;
}

int inversions() {
    int ret = 0;
    for (int i = n-1; i >= 0; --i) {
        ret += get(a[i] - 1);
        insert(a[i], 1);
    }
    return ret;
}

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << inversions() << endl;
}