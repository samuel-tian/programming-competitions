#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, input;
    cin >> n;
    int median[n][n], median2[n], sortarray[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j<n; j++){
            cin >> input;
            median[i][j] = input;
        }
    }
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            sortarray[col] = median[row][col];
        }
        sort(sortarray, sortarray+n);
        median2[row] = sortarray[(n-1)/2];
    }
    sort(median2, median2 + n);
    cout << median2[(n-1)/2] << endl;
}