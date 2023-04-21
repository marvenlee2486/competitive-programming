#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll m,n,t;
    cin >> m >> n >> t;
    if(t == 1){
        ll cur = n;
        for(int i = n - 1; i >= 1; i--){
            cur *= i;
            if(cur > m){
                cout << "TLE\n";
                return 0;
            }
        }
    }
    else if(t == 2){
        ll cur = 1;
        for(int i = 0; i < n; i++){
            cur *= 2;
            if(cur > m){
                cout << "TLE\n";
                return 0;
            }
        }
    } 
    else if(t == 3){
        ll cur = 1;
        for(int i = 0; i < 4; i++){
            cur *= n;
            if(cur > m){
                cout << "TLE\n";
                return 0;
            }
        }
    }
    else if(t == 4){
        ll cur = 1;
        for(int i = 0; i < 3; i++){
            cur *= n;
            if(cur > m){
                cout << "TLE\n";
                return 0;
            }
        }
    }
    else if(t == 5){
        ll cur = n * n;
        if(cur > m) {
            cout << "TLE\n";
            return 0;
        }
    }
    else if(t == 6){
        ll cur = ceil(n * log2(n));
        // cout << cur << "\n";
        if(cur > m){
            cout << "TLE\n";
            return 0;
        }
    } else{
        if( n > m) {
            cout << "TLE\n";
            return 0;
        }
    }

    cout << "AC\n";
}