#include <bits/stdc++.h>
using namespace std;
/*
x ^ y * y + y ^ x * x = n
y * x ( x ^ (y - 1) + y ^ (x - 1)) = n;

n / y * x = x ^ (y - 1) + y ^ (x - 1);

if x = 1

n / y = 2;
*/
void solve(){
    int n;
    cin >> n;
    if(n % 2 == 1) cout << "-1\n";
    else cout << "1 " << n/2 << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}