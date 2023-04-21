#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
        while(ans % 10 == 0) ans/=10;
        ans %= 1000000000;
    }
    if(n <= 7 ) cout << ans << "\n";
    else cout << setw(3) << setfill('0') << ans % 1000 << "\n";
}