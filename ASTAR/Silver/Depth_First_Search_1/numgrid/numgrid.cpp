#include <iostream>
#include <string>
#include <algorithm>
#include <set>
typedef std::pair<int,int> pii;
#define endl "\n"
using namespace std;

char grid[5][5];
string temp[5];
set<string> final;
void recurse(pii current, string append){
	
	if (append.length() == 6){
		//cout << append << " " << append.length() << endl;
		final.insert(append);
		return;
	}
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for (int i = 0; i < 4; i++){
		if (current.first + dx[i] <= 4 && current.first + dx[i] >= 0 && current.second + dy[i] <= 4 && current.second + dy[i] >= 0){
			recurse(make_pair(current.first + dx[i], current.second + dy[i]), append + string(1, grid[current.first+dx[i]][current.second+dy[i]]));
		}
	}
	
}
int main(){
	string input;
	for (int i = 0; i < 5; i++){
		cin >> input;
		temp[i] = input;
	}
	for (int k = 0; k < 5; k++){
		temp[k].erase( remove( temp[k].begin(), temp[k].end(), ' ' ), temp[k].end() );
	}
	for (int a = 0; a < 5; a++){
		for (int b = 0; b < 5; b++){
			grid[a][b] = temp[a][b];
		}
	}
	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 5; col++){
			recurse(make_pair(row, col), string(1, grid[row][col]));
		}
	}
	//for (int g = 0; g < final.size(); g++){
	//	cout << *std::next(final.begin(), g) << endl;
	//}
	cout << final.size() << endl;
}