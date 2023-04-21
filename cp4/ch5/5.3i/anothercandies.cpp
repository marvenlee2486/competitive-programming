#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll sum = 0,a;
        for(int i = 0; i < n; i++) {
            cin >> a;
            sum += a % n;
        }
        if(sum % n == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}