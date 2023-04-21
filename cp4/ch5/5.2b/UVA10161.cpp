#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    ll n;
    while(cin >> n && n){
        // 1 + 3 + 5    + 7 + 9 + .. n 
        // x <= n * n
        //
        ll x, y;
        ll term = sqrt(n);
        if(term % 2 == 0){
            // come back,
            ll t = 2 * term + 1;
            if(n == term*term){
                x = term;
                y = 1;
            }
            else if(n - term*term <= t/2){
                x = term + 1;
                y = n - term * term;
            }
            else{
                x = (term + 1) * (term + 1) - n + 1;
                y = term + 1;
            }
        }
        else{
            ll t = 2 * term + 1;
            if(n == term * term){
                y = term;
                x = 1;
            }else if(n - term* term <= t/2){
                y = term + 1;
                x = n - term * term;
            }
            else{
                y = (term + 1) * (term + 1) - n + 1;
                x = term + 1;
            }

        }

        cout << x << " " << y << "\n";

    }
}