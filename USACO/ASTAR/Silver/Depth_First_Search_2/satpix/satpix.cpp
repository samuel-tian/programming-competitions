#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;
typedef pair<int,int> pii;

int rows, cols, satelite[1000][80];

int floodfill(pii current){
	if (satelite[current.first][current.second] != 1 || current.first < 0 || current.first >= rows || current.second < 0 || current.second >= cols) return 0;
	int fillsize = 1;
	satelite[current.first][current.second] = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for (int i = 0; i < 4; i++){
		fillsize += floodfill(make_pair(current.first + dx[i], current.second + dy[i]));
	}
	return fillsize;
}

int main(){
	string input;
	cin >> cols >> rows;
	string temp[rows];
	for (int c = 0; c < rows; c++){
		cin >> input;
		temp[c] = input;
		cout << temp[c] << endl;
	}
	for (int a = 0; a < rows; a++){
		for (int b = 0; b < cols; b++){
			if (temp[a][b]=='*') satelite[a][b] = 1;
			else if (temp[a][b]=='.') satelite[a][b] = 2;
		}
	}
	vector<int> size;
	for (int x = 0; x < rows; x++){
		for (int y = 0; y < cols; y++){
			size.push_back(floodfill(make_pair(x, y)));
		}
	}
	int maxlength = 0;
	for (int e = 0; e < size.size(); e++){
		if (size[e] > maxlength) maxlength = size[e];
	}
	cout << maxlength << endl;
	return 0;
}