#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    int cur = 0;
    int ans = 1;
    int maxv = 0;
    vector<int> left;
    left.push_back(-1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') {
            cur++;
            left.push_back(i);
        }
        else {
            cur--;
            left.pop_back();
        }

        if (cur < 0) { left.clear(); left.push_back(i); cur = 0; }
        else {
            int len = i - left[cur];
            if ( len > maxv ) maxv = len, ans = 1;
            else if (len == maxv) ans++;
        }

    }
    if(maxv == 0) ans = 1;
    cout << maxv << " " << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while(_--){
        solve();
    }
}