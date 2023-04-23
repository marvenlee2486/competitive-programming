#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main(){
    ll l,r;
    cin >> l >> r;
    if(r - l + 1 >= 10){
        cout << "0\n";
    }
    else{
        ll minv = INF;
        for(ll i = l; i <= r; i++){
            ll temp = i;
            ll val = 1;
            while(temp != 0){
                val *= temp % 10;
                temp /= 10;
            }
            minv = min(minv, val);
        }
        cout << minv << "\n";
    }
}