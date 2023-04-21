#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    string s;
    while(cin >> n){
        getline(cin, s);
        getline(cin, s);
        while(n--){
            string ns = "";
            for(char c : s){
                if( (c >= '!' && c <= '*') || (c >= '[' && c <= ']')) ns += '\\';
                ns += c;
            }
            s = ns;
        }
        cout << s << "\n";
    }

}