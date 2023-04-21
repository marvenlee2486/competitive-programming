#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll x = 1,i;
        bool gg = false;
        while(n--){
            cin >> i;
            if(!gg) x = (x * i)/__gcd(x,i);
            if(x > 1e9) gg = true;
        }
        if(gg) cout << "More than a billion.\n";
        else cout << x << "\n";
    }
}