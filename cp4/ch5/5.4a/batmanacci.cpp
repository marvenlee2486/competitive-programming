#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// N
// A
// AN
// ANA
// ANAAN
// ANAANANA
// ANAANAN AANAAN

int main(){
    ll n,k;
    cin >> n >> k;
    k--;
    vector<ll> a(n, 0);
    a[0] = 1, a[1] = 1;
    int idx = -1;
    for(int i = 2; i < n; i++){
        a[i] = a[i-1] + a[i-2];
        if(a[i] >= k){
            idx = i;
            break;
        }
    }
    assert(idx != -1);
    while(idx > 1){
        //cout << idx << " " << k << "\n";
        if(k < a[idx - 2]) idx = idx - 2;
        else {

            k = k - a[idx - 2];
            idx = idx - 1;
        }
    }
    assert(k == 0);
    if(idx == 0) cout << "N\n";
    else cout << "A\n";

}