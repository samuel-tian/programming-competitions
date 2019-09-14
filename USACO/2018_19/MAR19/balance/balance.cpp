#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 100000

int n;
bool arr[MAXN * 2];
int leftFenwick[MAXN + 1], rightFenwick[MAXN + 1];
vector<int> firstones, firstzeroes, secondones, secondzeroes;

void insert(int fenwick[], int index, int val) {
	index += 1;
	while (index <= n) {
		fenwick[index] += val;
		index += index & (-index);
	}
//	cout << "INSERT FINISH" << endl;
}

int get(int fenwick[], int index) {
	int ret = 0;
	index += 1;
	while (index > 0) {
		ret += fenwick[index];
		index -= index & (-index);
	}
//	cout << "GET FINISH" << endl;
	return ret;
}

int inversions(bool arr[], int start, int end) {
	int ret = 0;
	int fenwick[2];
	fenwick[1] = 0;
	for (int i = end - 1; i >= start; i -= 2) {
//		cout << i << " ";
		ret += get(fenwick, arr[i] - 1);
		insert(fenwick, arr[i], 1);
//		cout << i << endl;
	}
	return ret;
}

int psum(int fenwick[], int l, int r) {
	if (l > r) return 0;
	return get(fenwick, r) - get(fenwick, l - 1);
}

int zeroesafter(int fenwick[], int index) {
	if (index == n - 1) return 0;
	return (n - index - 1) - psum(fenwick, index + 1, n - 1);
}

int onesbefore(int fenwick[], int index) {
	if (index == 0) return 0;
	return psum(fenwick, 0, index - 1);
}

int main() {
//	freopen("input.txt", "r", stdin);
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> arr[i];
		if (i < n) {
			if (arr[i]) firstones.insert(firstones.begin(), i);
			else firstzeroes.insert(firstzeroes.begin(), i);
		}
		else {
			if (arr[i]) secondones.push_back(i);
			else secondzeroes.push_back(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		insert(leftFenwick, i, arr[i]);
	}
	for (int i = n; i < 2 * n; ++i) {
		insert(rightFenwick, i - n, arr[i]);
	}
//	cout << inversions(arr, n, 2 * n) << " " << inversions(arr, 0, n) << endl;
	int leftInv = inversions(arr, 0, n);
	int rightInv = inversions(arr, n, 2 * n);
	int ret = abs(rightInv - leftInv);
	int crossswap = 0;
	for (int i = 0; i < min(firstzeroes.size(), secondones.size()); ++i) {
		crossswap += secondones[i] - firstzeroes[i];
//		 + zeroes after, - ones before
		leftInv = leftInv + zeroesafter(leftFenwick, firstzeroes[i]) - onesbefore(leftFenwick, firstzeroes[i]);
//		 - zeroes after, + ones before
		rightInv = rightInv - zeroesafter(rightFenwick, secondones[i] - n) + onesbefore(rightFenwick, secondones[i] - n);
		insert(leftFenwick, firstzeroes[i], 1);
		insert(rightFenwick, secondones[i] - n, -1);
		ret = min(ret, crossswap + abs(rightInv - leftInv));
	}
	crossswap = 0;
	leftInv = inversions(arr, 0, n);
	rightInv = inversions(arr, n, 2 * n);
	fill(leftFenwick, leftFenwick + n + 1, 0);
	fill(rightFenwick, rightFenwick + n + 1, 0);
	for (int i = 0; i < n; ++i) {
		insert(leftFenwick, i, arr[i]);
	}
	for (int i = n; i < 2 * n; ++i) {
		insert(rightFenwick, i - n, arr[i]);
	}
	for (int i = 0; i < min(firstones.size(), secondzeroes.size()); ++i) {
		crossswap += secondzeroes[i] - firstones[i];
//		 + zeroes after, - ones before
		rightInv = rightInv + zeroesafter(rightFenwick, secondzeroes[i] - n) - onesbefore(rightFenwick, secondzeroes[i] - n);
//		 - zeroes after, + ones before
		leftInv = leftInv - zeroesafter(leftFenwick, firstones[i]) + onesbefore(leftFenwick, firstones[i]);
//		cout << zeroesafter(leftFenwick, firstones[i]) << endl;
		insert(rightFenwick, secondzeroes[i] - n, 1);
		insert(leftFenwick, firstones[i], -1);
		ret = min(ret, crossswap + abs(rightInv - leftInv));
	}
	cout << ret << endl;
}

/*
print fenwick
for (int j = 0; j < n; ++j) {
	cout << psum(leftFenwick, j, j) << " ";
}
cout << endl;
 */
