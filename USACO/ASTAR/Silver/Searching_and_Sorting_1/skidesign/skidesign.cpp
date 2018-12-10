#include <iostream>
#define endl "\n"
using namespace std;

int main(){
	int n;
	cin >> n;
	int heights[n], input;
	for (int i = 0; i < n; i++){
		cin >> input;
		heights[i] = input;
	}
	int mincost = 2000000000;
	for (int j = 0; j <= 83; j++){
		int cost = 0, difference;
		for (int k = 0; k < n; k++){
			if (heights[k] < j) difference = j - heights[k];
			else if (heights[k] > j + 17) difference = heights[k] - (j + 17);
			else difference = 0;
			cost += difference * difference;
		}
		if (cost < mincost) mincost = cost;
	}
	cout << mincost << endl;
}