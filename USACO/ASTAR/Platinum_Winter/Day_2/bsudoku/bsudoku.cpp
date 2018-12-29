#include <iostream>
#include <climits>
#include <string>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define toggle(a) 1-a

int sudoku[9][9];

int main() {
    char c;
    string s;
    for (int i = 0; i < 9; ++i) {
        cin >> s;
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = s[j] - '0';
        }
    }
    
}
