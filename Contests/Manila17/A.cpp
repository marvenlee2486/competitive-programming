#include <bits/stdc++.h>
using namespace std;

void solve(){
    int minv = 101;
    for(int i = 0; i < 6; i++){
        int x;cin >> x;
        minv = min(minv,x);
    }
    int x;
    cin >> x;
    if(x <= minv) cout << "DATA IS BIAS!\n";
    else{
        cout << ceil((x - minv)*100.0/minv) << "% INCREASE!\n"; 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}