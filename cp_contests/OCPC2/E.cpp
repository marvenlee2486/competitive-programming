#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll l, r;
    cin >> l >> r;

    if((r - l + 1) % 2 == 0){
        for(int i = l; i <= r; i+=2) cout << i + 1<< " " << i << " ";
        cout << "\n";
    }
    else if( r % 2 == 0){
        cout << "-1\n";
    }else{
        if(l == r){
            if(l == 1) cout << "1\n";
            else cout << "-1\n";
            return;
        }

        cout << l + 2 << " " << l << " " << l + 1 << " ";
        for(int i = l + 3; i <= r; i+= 2)cout << i + 1<< " " << i << " ";
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}