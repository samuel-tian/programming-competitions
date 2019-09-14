#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX

int N;
int dirty[MAXN];
vector<int> compressed;
vector<stack<int> > soapy;

bool check(int n) {
	// cout << "N: " << n << endl;
	compressed.clear();
	soapy.clear();
	int plateCounter = 0;
	for (int i = 0; i < n; ++i) {
		compressed.push_back(dirty[i]);
	}
	sort(compressed.begin(), compressed.end());
	vector<int> tops;
	for (int i = 0; i < n; ++i) {
		int cur = dirty[i];
		// bool inserted = false;
		// for (int j = 0; j < soapy.size(); ++j) {
		// 	// maybe replace this with a binary search
		// 	if (cur < soapy[j].top()) {
		// 		soapy[j].push(cur);
		// 		inserted = true;
		// 		break;
		// 	}
		// }
		int loc = distance(tops.begin(), lower_bound(tops.begin(), tops.end(), cur));
		if (loc != soapy.size()) {
			soapy[loc].push(cur);
			tops[loc] = cur;
		}
		else {
			stack<int> s;
			s.push(cur);
			soapy.push_back(s);
			tops.push_back(cur);
		}
		// for (int j = 0; j < soapy.size(); ++j) {
		// 	cout << soapy[j].size() << " ";
		// }
		// cout << endl;
		if (soapy[0].top() == compressed[plateCounter]) {
			soapy[0].pop();
			++plateCounter;
			if (soapy[0].empty()) {
				soapy.erase(soapy.begin());
				tops.erase(tops.begin());
			}
			else {
				tops[0] = soapy[0].top();
			}
		}
	}
	while (plateCounter < n) {
		if (soapy[0].top() == compressed[plateCounter]) {
			soapy[0].pop();
			++plateCounter;
			if (soapy[0].empty()) {
				soapy.erase(soapy.begin());
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> dirty[i];
	}
	int lo = 1, hi = N, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			// cout << "works" << endl;
		}
		else {
			hi = mid - 1;
			// cout << "doesn't work" << endl;
		}
	}
	cout << mid << endl;
	// for (int i = 1; i <= N; ++i) {
	// 	if (check(i)) {
	// 		cout << i << ": WORKS" << endl;
	// 	}
	// 	else {
	// 		cout << i << ": DOESN'T WORK" << endl;
	// 	}
	// }
	return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX

int n;
int dishes[MAXN];
vector<int> compressedDishes;
vector<stack<int>* > stacks;

void pop() {
	stacks[0]->pop();
	if (stacks[0]->empty()) stacks.erase(stacks.begin());
}

void push(int dish) {
	if (stacks.empty() || dish > stacks[stacks.size() - 1]->top()) {
		stack<int>* s = new stack<int>;
		s->push(dish);
		stacks.push_back(s);
		return;
	}
	// binary search on insert position
	int low = 0;
	int high = stacks.size() - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (stacks[mid]->top() < dish) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	stacks[low]->push(dish);
}

bool simulate(int prefixSize) {
	stacks.clear();
	int counter = 0;
	int dishNum = 0;
	for (int i = 0; i < prefixSize; ++i) {
		compressedDishes.push_back(dishes[i]);
	}
	sort(compressedDishes.begin(), compressedDishes.end());
	while (counter < prefixSize) {
		if (!stacks.empty()) {
			if (stacks[0]->top() == compressedDishes[counter]) {
				pop();
				++counter;
				continue;
			}

		}
		if (dishNum == prefixSize) return false;
		push(dishes[dishNum++]);
	}
	return true;
}

int main() {
	ifstream ifs("input.txt", ios::in);
	ofstream ofs("output.txt", ios::out);
	ifs >> n;
	for (int i = 0; i < n; ++i) {
		ifs >> dishes[i];
	}
	int low = 0;
	int high = n - 1;
	while (low < high) {
		int mid = (low + high + 1) / 2;
		if (simulate(mid)) {
			low = mid;
		}
		else {
			high = mid - 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << simulate(i) << endl;
	}
	ofs << low << '\n';
}
*/
