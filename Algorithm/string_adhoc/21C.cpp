#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool valid(char c){
    return ( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}


bool solve(){
    string s;
    cin >> s;
    int st = 0;
    int len = 0;
    int host = 0;
    for(char c : s){
        if(c == '@'){
            if (st != 0) return false;
            if (len == 0 || len > 16) return false;
            st = 1;
            len = 0;
            continue;
        }
        else if (c == '/'){
            if (st != 1) return false;
            if (len == 0 || len > 16) return false;
            host += len;
            if (host == 0 || host > 32) return false;
            st = 2;
            len = 0;
            continue;
        }
        if(st != 1 && !( valid(c) )) return false;
        if(st == 1 && !valid(c) && c!='.' ) return false;
        len++;
        if(st == 1 && c == '.'){
            len--;
            if (len == 0 || len > 16) return false;
            host += len;
            len = 0;
        }
    }
    if(st == 1) host += len;
    if(len == 0 || len > 16) return false;
    if(host == 0 || host > 32) return false;
    if(st == 0) return false;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while(_--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}