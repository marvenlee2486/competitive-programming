#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,p;
    cin >> n >> p;
    char ans[n];
    memset(ans,0,sizeof ans);
    bool can = true;
    for(int i = 0; i < p ; i++){
        int a; string s;
        cin >> a >> s;
        a--;
        for(int idx = 0; idx < s.size() ; idx++){
            if(s[idx]=='*') break;
            if(ans[a+idx]!=0 && ans[a+idx]!=s[idx]) can = false;
            ans[a+idx] = s[idx];
        }
        int idxx = 0;
        for(int idx = s.size() - 1; idx >=0 ; idx--){
            if(s[idx]=='*') break;
            if(ans[n-1-idxx]!=0 && ans[n-1-idxx]!=s[idx]) can = false;
            ans[n-1-idxx] = s[idx];
            idxx++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(ans[i] == 0) can = false;
    }

    if(!can) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i = 0 ; i < n ; i++){
        cout << ans[i];
    }
    cout << "\n";
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}