#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF 0x7FFFFFFF
#define MAXN 100000

long long n;
long long leftfield[MAXN], rightfield[MAXN];
long long leftindex[MAXN], rightindex[MAXN];
long long leftpos[MAXN], rightpos[MAXN];
long long fenwick[MAXN+1];
// build rightindex from leftfield and leftindex from rightfield

void update(long long index) {
	while (index <= n) {
		fenwick[index] += 1;
		index += index & (-index);
	}
}

long long get(long long index) {
	long long sum = 0;
    while (index>0) {
		sum += fenwick[index];
		index -= index & (-index);
	}
	return sum;
}

long long inversions(long long arr[]) {
	long long ret = 0;
	for (long long i = 0; i <= n; ++i) {
		fenwick[i] = 0;
	}
	for (long long i = n-1; i >= 0; --i) {
		ret += get(arr[i]-1);
		update(arr[i]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (long long i = 0; i < n; ++i) {
		cin >> leftfield[i];
		leftindex[leftfield[i]-1]=i+1;
	}
	for (long long i = 0; i < n; ++i) {
		cin >> rightfield[i];
		rightindex[rightfield[i]-1]=i+1;
	}
	for (long long i = 0; i < n; ++i) {
		leftpos[i] = leftindex[rightfield[i]-1];
		rightpos[i] = rightindex[leftfield[i]-1];
	}
	// for (long long i = 0; i < n; ++i) {
	// 	cout << leftpos[i] << " ";
	// }
	// cout << endl;
	// for (long long i = 0; i < n; ++i) {
	// 	cout << rightpos[i] << " ";
	// }
	// cout << endl;
	long long cross = inversions(leftpos);
	long long mincross = cross;
	for (long long i = n - 1; i > 0; --i) {
		cross += 2*leftpos[i] - n - 1;
		mincross = min(mincross, cross);
	}
	cross = inversions(rightpos);
	mincross = min(mincross, cross);
	for (long long i = n - 1; i > 0; --i) {
		cross += 2*rightpos[i] - n - 1;
		mincross = min(mincross, cross);
	}
	cout << mincross << endl;
}
