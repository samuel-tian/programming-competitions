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
typedef queue<pii> qii;

int main(){														 // USACO
	stack<int> unwashed, washed, dried;
	int n, washedcount = 0;
	cin >> n;
	for (int i = n; i > 0; i--){
		unwashed.push(i);
	}
	qii command;
	pii com;
	while (washedcount < n){
		cin >> com.first >> com.second;
		command.push(mp(com.first, com.second));
		if (com.first == 2) washedcount += com.second;
	}
	int comcount = command.size();
	for (int i = 0; i < comcount; i++){
		if (command.front().first == 1){
			for (int j = 0; j < command.front().second; j++){
				washed.push(unwashed.top());
				unwashed.pop();
			}
		}
		else{
			for (int j = 0; j < command.front().second; j++){
				dried.push(washed.top());
				washed.pop();
			}
		}
		command.pop();
	}
	for (int i = 0; i < n; i++){
		cout << dried.top() << endl;
		dried.pop();
	}
}