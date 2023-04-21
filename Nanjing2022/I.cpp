#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    for(char c:s) cnt[c -'a']++;
    int maxv = 0;
    for(int i = 0; i < 26; i++) maxv = max(maxv, cnt[i]);
    cout << s.size() - maxv << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}