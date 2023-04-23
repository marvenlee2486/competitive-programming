#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i != 0 && a[i] % 2 == a[i-1] % 2) ans++; 
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}