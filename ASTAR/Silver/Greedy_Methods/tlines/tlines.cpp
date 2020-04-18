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
#define maxn 50000
#define debug cout << "pass" << endl;
#define iter set<int>::iterator
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int n; pii coor[maxn];
bool three_same(){
	set<int> first;
	for (int i = 0; i < n; i++){
		first.insert(coor[i].f);
		if (first.size() > 3){
			return false;
		}
	}
	return true;
}
bool two_same(){
	pii temp[maxn] = coor;
	set<int> second;
	for (int i = 0; i < n; i++)
		second.insert(temp[i].s);
	for (iter it = second.begin(); it != second.end(); it++){
		int i = *it;
		int temp2;
		for (int j = 0; j < n; j++){
			if (temp[j].s == i){
				temp2 = temp[j].f;
				temp[j].f = -1;
			}
		}
		set<int> first;
		for (int i = 0; i < n; i++){
			if (temp[i].f != -1){
				first.insert(temp[i].f);
				if (first.size() > 2){
					return false;
				}
			}
		}
		for (int j = 0; j < n; j++)
			if (temp[j].f == -1)
				temp[j].f = temp2;
	}
	return true;
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> coor[i].f >> coor[i].s;
	bool possible = false;
	if (three_same() == true || two_same() == true)
		possible = true;
	for (int i = 0; i < n; i++){
		int temp = coor[i].s;
		coor[i].s = coor[i].f;
		coor[i].f = temp;
	}
	if (three_same() == true || two_same() == true)
		possible = true;
	cout << possible << endl;
	return 0;
}