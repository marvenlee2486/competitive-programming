#include<bits/stdc++.h>
using namespace std;

pair<string, int> transform(string s){
    string ans = "";
    int Bcnt = 0;
    for(char c: s){
        if(c=='B') {
            Bcnt ++;
            continue;
        }
        if(ans.size() !=0 && c == ans.back()) ans.pop_back();
        else ans.push_back(c);
    }
    return make_pair(ans,Bcnt%2);
}

void solve(){
    string u,v;
    int bu,bv;
    cin >> u >> v;
    tie(u,bu) = transform(u);
    tie(v,bv) = transform(v);
    if(bu!=bv || u != v) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}