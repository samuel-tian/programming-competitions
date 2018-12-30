#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXN 50000

int n;
int arr[MAXN];
int fenwick[MAXN+1];
// one-indexed

void insert(int index, int val) {
	index = index + 1;
	while (index <= n) {
		fenwick[index] += val;
		index += index & (-index);
	}
}

int get(int index) {
	int sum = 0;
	index = index + 1;
    while (index>0) {
		sum += fenwick[index];
		index -= index & (-index);
	}
	return sum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		insert(i, arr[i]);
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
