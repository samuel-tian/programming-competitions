#include <iostream>
using namespace std;

int main(){
    int r, c, input;
    cin >> r >> c;
    int grass[r][c], sum = 0, maxsum[3];
    for(int i = 0; i < r; i++){
        for(int j = 0; j<c; j++){
            cin >> input;
            grass[i][j] = input;
        }
    }
    maxsum[0] = 0;
    for (int row = 0; row < r - 3; row++){
        for(int col = 0; col < c - 3; col++){
            sum = 0;
            for(int sumrow = row; sumrow <= row+2; sumrow++){
                for(int sumcol = col; sumcol <= col+2; sumcol++){
                    sum += grass[sumrow][sumcol];
                }
            }
            if (sum > maxsum[0]){
                maxsum[0] = sum;
                maxsum[1] = row;
                maxsum[2] = col;
            }
        }
    }
    cout << maxsum[0] << endl;
    cout << maxsum[1] + 1 << " " << maxsum[2] + 1 << endl;
}
