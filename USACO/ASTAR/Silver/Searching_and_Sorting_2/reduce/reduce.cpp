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
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;
bool comp(pii a, pii b){
	return a.second < b.second;
}
int main(){														 // USACO
	int n;
	cin >> n;
	pii coor[n];
	int rightx[4], leftx[4], topy[4], bottomy[4];
	for (int i = 0; i < n; i++){
		cin >> coor[i].first >> coor[i].second;
	}
	sort(coor, coor+n);
	for (int i = 0; i < 4; i++){
		leftx[i] = coor[i].first;
		rightx[i] = coor[n-i-1].first;
	}
	sort(coor, coor+n, comp);
	for (int i = 0; i < 4; i++){
		bottomy[i] = coor[i].second;
		topy[i] = coor[n-i-1].second;
	}
	for (int i = 0; i < 4; i++){
		cout << leftx[i] sp rightx[i] sp bottomy[i] sp topy[i] << endl;
	}
	int minarea = inf;
	for (int a = 0; a < 4; a++){
		for (int b = 0; b < 4; b++){
			for (int c = 0; c < 4; c++){
				for (int d = 0; d < 4; d++){
					int removed = 0;
					for (int i = 0; i < n; i++){
						if (coor[i].second > topy[d] || coor[i].second < bottomy[c] || coor[i].first > rightx[b] || coor[i].first < leftx[a]) removed++;
					}
					if (removed <= 3){
						int area = abs(rightx[b] - leftx[a]) * abs(bottomy[c] - topy[d]);
						if (area < minarea){
							minarea = area;
						}
					}
				}
			}
		}
	}
	cout << minarea << endl;
}