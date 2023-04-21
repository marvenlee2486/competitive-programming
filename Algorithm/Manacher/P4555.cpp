#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define chkmax(x,y) x = max(x,y);

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
    // for(char c : s) cout << c << " ";
    // cout << "\n";
    // for(int c: d) cout << c << " ";
    // ll ret = 0;
    // for(int c:d) ret += (c)/2;
    // return ret;
    return d;
}

void solve(string s){

    vector<int> d = manacher(s);
    int maxv = 0;
    int n = d.size();
    vector<int> st (n+1, 0);
    vector<int> en (n+1, 0);
    for(int i = 1; i < d.size(); i++){
        chkmax(st[i - d[i] + 1] , (d[i] - 1) );
        chkmax(en[i + d[i] - 1] , (d[i] - 1) );
    }
    // for(int c : d) cout << c << " ";
    // cout << "\n";
    // for(int c : st) cout << c << " ";
    // cout << "\n";
    // for(int c : en) cout << c << " ";
    // cout << "\n";

    int cur = 0;
    for(int i = 0; i < n; i++){
        cur = max(cur, st[i]);
        if(cur == 0 || en[i] == 0) {
            cur--;
            continue;
        }
        chkmax(maxv, cur + en[i]);
        cur --;
    }
    for(int i = n - 1; i >= 0; i--){
        cur = max(cur, en[i]);
        if(cur == 0 || st[i] == 0){
            cur--;
            continue;
        }
        chkmax(maxv, st[i] + cur);
        cur --;
    }
    cout << maxv;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    solve(s);
}