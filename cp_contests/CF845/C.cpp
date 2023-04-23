/*

ai % 1,2,3,4,5,6
ai % 1,2,3,4,5,6

*/

// n * (n - 1) * n !

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 2;
const ll MOD = 1e9 + 7;
vector< vector<int> > factors(N, vector<int>());
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m + 1, 0);
    int left = m;
    for(auto& i:a) cin >> i;
    sort(a.begin(),a.end());
    
    int l = 0, r = 0;
    int ans = MOD;
    while(r < n){
        
        for(int fac: factors[a[r]]){
            if(fac > m) break;
            if(cnt[fac] == 0) left--;
            cnt[fac] += 1;
        }
        while(left == 0){
            ans = min(ans, a[r] - a[l]);
            
            for(int fac: factors[a[l]]){
                if(fac > m) break;
                cnt[fac] -= 1;
                if(cnt[fac] == 0) left++;
            }
            l++;
        }
        r++;
    }
    if(ans == MOD) ans = -1;
    cout << ans << "\n";
}

int main(){
    for(int i = 1; i < N; i++){
        int j = 1;
        while(j <= sqrt(i)){
            if(i % j == 0){
                factors[i].emplace_back(j);
                if(j != i/j)factors[i].emplace_back(i/j);
            }
            
            j++;
        }
        sort(factors[i].begin(),factors[i].end());
    }
    int t;
    cin >> t;
    while(t--) solve();
}