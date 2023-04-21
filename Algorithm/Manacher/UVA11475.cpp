#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

vector<int> manacher(string _s){
    string s = "#";
    for(char c:_s) s += c, s += '#';
    int n = s.size();
    vector<int> d(n);
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r)? 1 : min(d[l + r - i], r - i + 1);
        while(0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        d[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
    }
    // for(int c: d) cout << c << " ";
    // ll ret = 0;
    // for(int c:d) ret += (c)/2;
    // return ret;
    return d;
}

void solve(string s){

    vector<int> d = manacher(s);
    int loc = -1;
    for(int i = d.size() - 1; i >= 0; i--){
        if(d[i] + i  == d.size()){
            loc = i;
        }
    }

    if(loc % 2){
        loc /= 2;
        loc -= (s.size() - loc);
        for(int i = loc; i >= 0; i--) s += s[i];
    }
    else{
        loc /= 2;
        loc -= s.size() - loc + 1;
        for(int i = loc; i >= 0; i--) s += s[i];
    }
    cout << s << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin >> s)
        solve(s);
}