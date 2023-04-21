#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string solve(){
    string s, source, target;
    cin >> s >> source >> target;

    ll val = 0;
    for(char c: s){
        val *= source.size();
        for(int i = 0; i < source.size(); i++){
            if(c == source[i]){
                val += i;
                break;
            }
        }
    }

    string ans = "";
    while(val != 0){
        ans += target[val % target.size()];
        val /= target.size();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) cout << "Case #" << i+1 << ": " << solve() <<"\n";
}