#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll convert(string s, int base){
    ll res = 0;
    for(char c: s){
        res *= base;
        if(c >= '0' && c <= '9') res += c - '0';
        else res += c - 'a' + 10; 
    }
    return res;
}

bool possible(string s, int base){
    for(char c: s){
        int val = 0;
        if(c >= '0' && c <= '9') val = c - '0';
        else val = c - 'a' + 10; 
        if(base == 1 && val != 1) return false; 
        if(base != 1 && val >= base) return false;
    }
    if(convert(s,base) >= (1ll << 32)) return false;
    return true;
}
void solve(){
    string s1,s2,op,res,dummy;
    cin >> s1 >> op >> s2 >> dummy >> res;
    bool gg = true;
    for(int i = 1; i <= 36; i++){
        if(!possible(s1,i) || !possible(s2,i) || !possible(res,i)) continue;

        ll v1 = convert(s1,i);
        ll v2 = convert(s2,i);
        ll vexp = 0;
        ll vres = convert(res,i);

        if(op == "+") vexp = v1 + v2;
        else if( op == "-") vexp = v1 - v2;
        else if( op == "*") vexp = v1 * v2;
        else if( op == "/") vexp = (v1 % v2 == 0)? v1/v2 : -1;

        if( vexp == vres){
            if(i < 10) cout << (char)('0' + i);
            else if(i == 36) cout << "0";
            else cout << (char)('a' + i - 10);
            gg = false;
        }
    }
    if(gg) cout << "invalid";
    cout << "\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();

}