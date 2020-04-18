// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef pair<int, int> pii;

vector<pair<string, int> > dict;
int w, n;

bool autoComplete(string partialWord, string completeWord) {
	if (partialWord.length() > completeWord.length()) {
		return false;
	}
	return (completeWord.substr(0, partialWord.length()) == partialWord);
}

/*int binarySearch(vector<pair<string, int> > dict, string word, int start, int end) {
	while (start <= end) {
		int middle = (start + end) / 2;
		if (autoComplete(word, dict[middle].f)) {
			while (middle-1 >= 0 && autoComplete(word, dict[middle-1].f)) {
				middle--;
			}
			return middle;
		}
		else if (word.compare(dict[middle].f) < 0) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return -1;
}*/

int main() {
	//freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_2/auto/auto_cases/10.in", "r", stdin);

	cin >> w >> n;
	for (int i = 0; i < w; i++) {
		string temp;
		cin >> temp;
		dict.pb(mp(temp, i+1));
	}
	sort(dict.begin(), dict.end());
	/*for (int i = 0; i < (int) dict.size(); i++) {
		cout << dict[i].f sp dict[i].s << endl;
	}*/

	for (int i = 0; i < n; i++) {
		int kthCompletion; string partialWord;
		cin >> kthCompletion >> partialWord;
		//int pos = binarySearch(dict, partialWord, 0, (int) (dict.size() - 1));
		int pos = lower_bound(dict.begin(), dict.end(), mp(partialWord, 0)) - dict.begin();
		int current = pos + kthCompletion - 1;
		if (current < (int) (dict.size()) && autoComplete(partialWord, dict[current].f)) {
			cout << dict[current].s << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	//fclose(stdin);
	return 0;
}
