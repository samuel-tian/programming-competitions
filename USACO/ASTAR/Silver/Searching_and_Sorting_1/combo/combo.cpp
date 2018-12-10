#include <iostream>
#include <cmath>
using namespace std;

struct Lock{
    int a, b, c;
};

bool close(Lock combo, Lock actual, int N){
    bool boola = abs(combo.a - actual.a) <= 2 || abs(combo.a - actual.a) >= N-2;
    bool boolb = abs(combo.b - actual.b) <= 2 || abs(combo.b - actual.b) >= N-2;
    bool boolc = abs(combo.c - actual.c) <= 2 || abs(combo.c - actual.c) >= N-2;
    return (boola && boolb && boolc);
}

int main(){
    Lock m, f, inputlock;
    int n, count = 0;
    cin >> n;
    cin >> f.a >> f.b >> f.c >> m.a >> m.b >> m.c;
    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= n; y++){
            for (int z = 1; z <= n; z++){
                inputlock.a = x;
                inputlock.b = y;
                inputlock.c = z;
                if (close(inputlock, m, n) == 1 || close(inputlock , f, n) == 1){
                    count++;

                }
            }
        }
    }
    cout << count << endl;
}
