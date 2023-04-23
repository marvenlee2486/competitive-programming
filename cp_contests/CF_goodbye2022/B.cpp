#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
using vl = vector<ll>;

#define rep(i,a,b) for(int i = (a); i < (b); i++)

void solve(){
    int n,k;
    cin >> n >> k;

    vl a(n,0);
    int l = 1, r = n;
    for(int i = k - 1; i < n; i+=k){
        a[i] = l++;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 0) a[i] = r--;
        
    }
    rep(i,0,n) cout << a[i] << " ";
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}