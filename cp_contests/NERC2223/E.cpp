#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,a,b;
    cin >> n >> a >> b;
    if(a > b) {
        cout << "1\n";
        return;
    }

    cout << (n+a-1)/a  << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);  
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}