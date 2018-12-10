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
	queue<int> paylist;
	queue< pair<string,int> > commands;
	pair<string,int> input;

	// freopen("testing.txt", "r", stdin);
	int n; cin >> n;
	queue<int> registers[n];
	while (cin >> input.first >> input.second){
		commands.push(mp(input.first, input.second));
		
	}
	// cin >> input.first >> input.second;
	// commands.push(mp(input.first, input.second));
	int size = commands.size();
	for (int i = 0; i < size; i++){
		if (commands.front().first == "C"){
			paylist.push(commands.front().second);
		}
		else{
			registers[commands.front().second - 1].push(paylist.front());
			paylist.pop();
		}
		commands.pop();
	}
	for (int i = 0; i < n; i++){
		size = registers[i].size();
		cout << size << " ";
		for (int j = 0; j < size; j++){
			cout << registers[i].front() << " ";
			registers[i].pop();
		}
		cout << endl;
	}
}
