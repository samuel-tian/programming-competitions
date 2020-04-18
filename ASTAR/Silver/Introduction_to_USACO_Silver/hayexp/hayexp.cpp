#include <iostream>
using namespace std;

int main(){
    int N, Q, day, querystart, queryend;
    cin >> N >> Q;
    int dayarray[N], queryastart[Q], queryaend[Q], sum[Q];
    for (int i = 0; i < N; i++){
        cin >> day;
        dayarray[i] = day;
    }
    for (int j = 0; j < Q; j++){
        cin >> querystart >> queryend;
        queryastart[j] = querystart;
        queryaend[j] = queryend;
    }
    for (int k = 0; k < Q; k++){
        sum[k] = 0;
        for (int q = queryastart[k] - 1; q < queryaend[k]; q++){
            sum[k] += dayarray[q];
        
        }
        cout << sum[k] << endl;
    }
    
}