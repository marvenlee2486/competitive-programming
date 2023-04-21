#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    long long nn;
    cin >> nn;
    n = nn;
    for(ll i = 128; i >= 1; i--){
        ll div = pow(9,9);
        if(n % div == 0){
            cout << (long long)i << "\n";
            break;
        }
    }
}
