#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s,t;
    cin >> s >> t;
    int n = s.size();
    vector<int> a[26];
    for(int i = 0; i < n; i++){
        a[s[i] - 'a'].emplace_back(i);
    }
    int ans = 1, cur = -1;
    for(char c: t){
        auto it = upper_bound(a[c - 'a'].begin(), a[c - 'a'].end(),cur);
        if(it == a[c - 'a'].end()){
            ans++;
            cur = *a[c - 'a'].begin();
        }
        else{
            cur = *it;
        }
    }
    cout << ans << "\n";

}