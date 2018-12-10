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
#define debug cout << "pass" << endl;
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
	int n; cin >> n;
	pair<int, vector<int> > cows[n];
	int signaltime[n], endtime[n];
	bool ran[n];
	vector<int> waiting, running;
	for (int i = 0; i < n; i++){
		int temp, temp2;
		cin >> cows[i].f >> temp;
		for (int j = 0; j < temp; j++){
			cin >> temp2;
			cows[i].s.pb(temp2-1);
		}
	}
	for (int i = 0; i < n; i++){
		ran[i] = false;
		signaltime[i] = 0;
		endtime[i] = 0;
		waiting.pb(i);
	}
	int counter = 0;
	ran[0] = true;
	endtime[0] = cows[0].f;
	waiting.erase(remove(waiting.begin(), waiting.end(), 0), waiting.end());
	running.pb(0);
	while (!waiting.empty() || !running.empty()){
		++counter;
		//cout << counter << endl;
		//cout << counter sp endtime[4] << endl;
		int size = running.size();
		for (int i = 0; i < size; i++){
			
			int current = running[i];
			//bool test = (endtime[current] == counter);
			//cout << test << " ";
			//cout << current sp endtime[current] sp counter << endl;
			if (endtime[current] <= counter){
				for (int j = 0; j < cows[current].s.size(); j++){
					int next = cows[current].s[j];
					if (ran[next] == false){
						//cout << "next" sp next << endl;
						signaltime[next] = endtime[current];
						ran[next] = true;
						waiting.erase(remove(waiting.begin(), waiting.end(), next), waiting.end());
						running.pb(next);
						endtime[next] = signaltime[next] + cows[next].f;
					}
				}
				running.erase(remove(running.begin(), running.end(), current), running.end());
			}
		}
		/*cout << "waiting ";
		for (int i = 0; i < waiting.size(); i++)
			cout << waiting[i] << " ";
		cout << endl;
		cout << "running ";
		for (int i = 0; i < running.size(); i++)
			cout << running[i] << " ";
		cout << endl;
		cout << "ran ";
		for (int i = 0; i < n; i++)
			cout << ran[i] << " ";
		cout << endl << endl;*/
	}
	
	cout << counter << endl;
}