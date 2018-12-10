#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;
typedef pair<int,int> pii;

int grid[750][750];
int rows, cols;
int floodfill(int xcor, int ycor){
	if (grid[xcor][ycor]!=1 || xcor < 0 || xcor >= rows || ycor < 0 || ycor >= cols) return 0;
	int fillsize = 1;
	grid[xcor][ycor] = 0;
	int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	for (int i = 0; i < 8; i++){
		fillsize += floodfill(xcor + dx[i], ycor + dy[i]);
	}
	return fillsize;
}
int main(){
	string input;
	cin >> cols >> rows;
	string temp[rows];
	for (int a = 0; a < rows; a++){
		cin >> input;
		temp[a] = input;
	}
	vector<int> size;
	for (int b = 0; b < rows; b++){
		for (int c = 0; c < cols; c++){
			if (temp[b][c]=='.') grid[b][c] = 1;
			else if (temp[b][c] == '*') grid[b][c] = 2;
		}
	}
	for (int r = 0; r < rows; r++){
		for (int s = 0; s < cols; s++){
			size.push_back(floodfill(r, s));
		}
	}
	int maxlength = 0;
	for (int d = 0; d < size.size(); d++){
		if (size[d] > maxlength) maxlength = size[d];
	}
	cout << maxlength << endl;
	return 0;

}