#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve(int n){
    if( n == 1) cout << "1\n";
    else cout << n + (n - 2) << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    while(cin >> t)
        solve(t);
}