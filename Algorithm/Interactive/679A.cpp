#include <bits/stdc++.h>
using namespace std;

bool q(int x){
    cout << x << endl;
    string s;
    cin >> s;
    return s=="yes";
}


int main(){
    int poss[] = {
        2,3,5,7,11,
        13,17,19,23,29,
        31,37,41,43,47,
    };
    int cnt = 0;
    for(int i=0;i<15;i++){
        if(q(poss[i])){
            cnt++;
            if(poss[i]*poss[i] <= 100){
                if(q(poss[i]*poss[i])) cnt++;
            }
        }
        if(cnt>=2) {
            cout << "composite" << endl;
            return 0;
        }
    }
    cout << "prime" << endl;
    return 0;
}