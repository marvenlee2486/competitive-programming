#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int ans = -1;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'R' && s[i + 1] == 'L') {
            ans = 0;
            break;
        }
        else if(s[i] == 'L' && s[i + 1] == 'R'){
            ans = i + 1;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}