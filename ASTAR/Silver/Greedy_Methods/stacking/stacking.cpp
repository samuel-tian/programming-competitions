/*input
7 4
5 5
2 4
4 6
3 5
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct Instruct{
    int start, end;
};

int main(){
    int n, k, a, b;
    cin >> n >> k;
    Instruct instructions[k];
    for (int i = 0; i < k; i++){
        cin >> a >> b;
        instructions[i].start = a;
        instructions[i].end = b;
    }
    int difference[n], stack[n];
    for (int j = 0; j < n; j++){
        difference[j] = 0;
        stack[j] = 0;
    }
    for (int action = 0; action < k; action++){
        difference[instructions[action].start]++;
        difference[instructions[action].end+1]--;
    }
    for (int pile = 0; pile < n; pile++){
        if (pile == 0) stack[0] = difference[pile];
        else stack[pile] = stack[pile - 1] + difference[pile];
    }
    sort(stack, stack + n);
    cout << stack[n/2] << endl;
}