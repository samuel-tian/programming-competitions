#include <iostream>
using namespace std;

void ruler(int n){
    if (n==1) cout << "*" << endl;
    else{
        ruler(n-1);
        for (int i = 0; i < n; i++){
            if (i==n-1) cout << "*" << endl;
            else cout << "*";
        }
        ruler(n-1);
    }
}

int main(){
    int n;
    cin >> n;
    for (int j = 0; j < n; j++){
        if (j==n-1) cout << "*" << endl;
        else cout << "*";
    }
    ruler(n-1);
    for (int k = 0; k < n; k++){
        if (k==n-1) cout << "*" << endl;
        else cout << "*";
    }
}
