#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    while(getline(cin, s)){
        string token;
        stringstream ss(s);
        ll x = 1;
        while(getline(ss,token,' ')){
            ll i = stoll(token);
            x = (x / __gcd(i,x)) * i;
        }
        cout << x << "\n";
    }
}