#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt1 = 0,cnt2 =0;
    for(char c: s){
        if(c == 'D') cnt1++;
        else cnt2++;
    }
    if(cnt1 == 3) cout << "DRX\n";
    else cout << "T1\n";
}