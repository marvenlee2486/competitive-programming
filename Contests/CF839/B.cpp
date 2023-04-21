#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool solve(){
    int a[2][2];
    for(int i = 0;i < 2; i++) for(int j = 0; j < 2; j++) cin >> a[i][j];
    for(int i = 0; i < 4;i++){
        // cout << a[0][0] << " " << a[0][1] << "\n";
        // cout << a[1][0] << " " << a[1][1] << "\n";
        if(a[0][0] < a[0][1] && a[1][0] < a[1][1] && a[0][0] < a[1][0] && a[0][1] < a[1][1]) return true;
        
        int x = a[0][0];
        a[0][0] = a[1][0];
        a[1][0] = a[1][1];
        a[1][1] = a[0][1];
        a[0][1] = x;
    }
    return false;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) cout << (solve()? "YES\n":"NO\n");
}

