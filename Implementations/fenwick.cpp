#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXN 50000

int n;
// one-indexed

void insert(int fenwick[], int index, int val) {
	index = index + 1;
	while (index <= n) {
		fenwick[index] += val;
		index += index & (-index);
	}
}

int get(int fenwick[], int index) {
	int sum = 0;
	index = index + 1;
    while (index>0) {
		sum += fenwick[index];
		index -= index & (-index);
	}
	return sum;
}

// inversion counting on an array
int inversions(int arr[]) {
	int ret = 0;
	int maxelement = 0;
	for (int i = 0; i < n; ++i) {
		maxelement = max(maxelement, arr[i]);
	}
	int bitree[maxelement+1];
	for (int i = 1; i <= maxelement; ++i) {
		bitree[i] = 0;
	}
	for (int i = n-1; i >= 0; --i) {
		ret += get(arr[i]-1);
		insert(arr[i], 1);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int fenwick[n+1];
	fill(fenwick, fenwick+n+1, 0);
	for (int i = 0; i < n; ++i) {
		insert(fenwick, i, arr[i]);
	}
	// range queries
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		cout << get(b-1) - get(a-2) << endl;
	}
}
