#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 3){
        cout << "NO\n";
        return;
    }
    if(n % 2 == 1){
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            cout << ((i % 2)? -1 * n/2 : n/2 - 1) << " ";
        }
        cout << "\n";
    }
    else{
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            cout << ((i % 2)? "-1 ": "1 ");
        }
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