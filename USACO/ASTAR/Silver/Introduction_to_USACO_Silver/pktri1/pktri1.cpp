#include <iostream>
using namespace std;

int main(){
    int N, S, current;
    cin >> N >> S;
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            current = (S + (col * (col + 1))/2 + row) % 9;
            if (current == 0) current = 9;
            if (row > col) cout << "  ";
            else if (col == N-1) cout << current << endl;
            else cout << current << " ";
        }
    }
}
