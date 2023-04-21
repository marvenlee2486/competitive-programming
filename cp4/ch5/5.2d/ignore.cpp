// 2 - 2
// 5 - 5
// 1 - 1
// 0 - 0
// 6 - 9
// 8 - 8

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string pair = "0125986";
    while(cin >> n){
        string s = "";
        while(n != 0){
            s += pair[n%7];
            n/=7;
        }
        cout << s << "\n";
    }
}