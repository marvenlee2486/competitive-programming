#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll x,y,n;
    ld r;
    while(cin >> x >> y >> n >> r && n){
        // initially
        // x   x1 = x0 * (100 + r/12 )/100 - y;
        //     x2 = x1 * (100 + r/12 )/100 - y;

        // end of i-th month, 
        // x = x0 * ((100 + r/12 )/100 )^n - (y + (100 + r/12 )/100 * y + )
        // x = ... - (y * ()^n)/((100 + r/12 )/100 - 1)


        n *= 12;
        ld d = r/1200 + 1;
        ld temp;
        if(r == 0){
            temp = x - y * n;
        }
        else{
            ld val = pow(d, n);
            temp = x * val - y * (val - 1) / (d - 1);
        }
        if(temp < 0) cout << "YES\n";
        else cout << "NO\n";
    
    }
}