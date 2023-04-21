#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    string s1,s2;
    cin >> n >> m >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i < n; i++){
        if(s1[i] == s1[i - 1]) cnt1++;
        
    }
    for(int i = 1; i < m; i++){
        if(s2[i] == s2[i - 1]) cnt2++;
    }

    if( (cnt1 == 0 && cnt2 == 0) || 
    (min(cnt1, cnt2) == 0 && max(cnt1, cnt2) == 1 && s1[n - 1] != s2[m - 1] )   )
        cout << "YES\n";
    else cout << "NO\n"; 
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}