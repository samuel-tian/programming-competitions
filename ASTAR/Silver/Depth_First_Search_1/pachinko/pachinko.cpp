/*input
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
#include <iostream>
#define endl "\n"
using namespace std;

int maxscore = 0;
void recurse(int row, int col, int score, int n, int grid[25][25]){
    score += grid[row][col];
    if (row == n - 1){
        if (score > maxscore) maxscore = score;
        return;
    }
    else{
        recurse(row + 1, col, score, n, grid);
        recurse(row + 1, col + 1, score, n, grid);
    }
}

int main(){
    int input, n;
    cin >> n;
    int grid[25][25];
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> input;
            grid[i][j] = input;
        }
    }
    recurse(0, 0, 0, n, grid);
    cout << maxscore << endl;
}
