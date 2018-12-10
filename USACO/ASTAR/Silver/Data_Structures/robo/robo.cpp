#include <bits/stdc++.h>	//includes everything, supported in CF, usaco, not POJ
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define p 1000000007
#define eps 1e-9
#define maxn 100010
using namespace std;
 
typedef pair<int, int> pii;

int main(){														 // USACO
	int n;
	cin >> n;
	string dirs[n];
	stack<int> final;
	for (int i = 0; i < n; i++) cin >> dirs[i];
	int counter = 1;
	for (int i = 0; i < n; i++){
		if (dirs[i] == "ADD"){
			final.push(counter);
			counter++;
		}
		else final.pop();
	}
	int size = final.size();
	stack<int> copy;
	for (int i = 0; i < size; i++){
		copy.push(final.top());
		final.pop();
	}
	size = copy.size();
	cout << size << endl;
	for (int i = 0; i < size; i++){
		cout << copy.top() << endl;
		copy.pop();
	}
}