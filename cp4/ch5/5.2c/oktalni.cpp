#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    while(s.size() % 3 != 0) s = "0" + s;

    for(int i = 0; i < s.size(); i += 3){
        string n = s.substr(i,3);
        int val = 0;
        for(char c:n) {
            val *= 2;
            val += c - '0';
        }
        cout << val;
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}