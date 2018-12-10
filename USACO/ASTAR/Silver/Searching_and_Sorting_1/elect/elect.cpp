#include <iostream>
#include <algorithm>
using namespace std;

struct Vote{
    int firstvote, secondvote, tag;
};

bool comp1(Vote a, Vote b){
    return a.firstvote < b.firstvote;
}

bool comp2(Vote a, Vote b){
    return a.secondvote < b.secondvote;
}

int main(){
    int n, k, firstin, secondin;
    cin >> n >> k;
    Vote votes[n];
    for (int i = 0; i < n; i++){
        cin >> firstin >> secondin;
        votes[i].firstvote = firstin;
        votes[i].secondvote = secondin;
        votes[i].tag= i;
    }
    sort(votes, votes + n, comp1);
    sort(votes+n-k, votes+n, comp2);
    cout << votes[n-1].tag + 1<< endl;
    return 0;
}
