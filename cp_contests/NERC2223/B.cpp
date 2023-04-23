#include<bits/stdc++.h>
using namespace std;
bool solve(){
    int n; cin >> n;
    string s;
    cin >> s;
    if(s.size() % 3 == 2) return false;

    for(int i = 0; i < s.size()/3; i++){
        if(s[3*i+1]!=s[3*i+2]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);  
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) cout << ((solve())? "YES\n":"NO\n");
}