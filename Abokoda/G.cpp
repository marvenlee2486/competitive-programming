#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;
int main(){
    ll n,k,x;
    cin >> n >> k >> x;
    ll lower = 0, upper = 0;
    while(n--){
        ll minv = INF, maxv = 0;
        for(int i = 0; i < k; i++){
            ll c;
            cin >> c;
            minv = min(minv, c);
            maxv = max(maxv, c);
        }
        lower += minv, upper += maxv;
    }
    if(x <= lower){
        cout << "ALWAYS\n";
    }
    else if(x > upper){
        cout << "NEVER\n";
    }
    else{
        cout << "SOMETIMES\n";
    }
}