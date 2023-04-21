#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a (n,0);
    ll ans = 1;
    for(int i = 0; i < n; i++) { cin >> a[i]; ans += a[i]; }
    sort(a.begin(),a.end());
    deque<ll> q;
    for(int i = 0; i < n; i++) q.push_back(a[i]);
    ll cur = 0;
    int choice = 0;
    while(q.size()!=0){
        // read from largest
        // cout << q.size() << " ";
        if(choice == 0){
            cur += q.back();
            if(cur > m){
                ans++;
                choice = 1 - choice;
                cur = q.back();
                q.pop_back();
            }
            else{
                cur = q.back();
                q.pop_back();
                choice = 1 - choice;
            }
        }else{
            cur += q.front();
            if(cur > m){
                ans++;
                choice = 0;
                cur = 0;
            }
            else{
                cur = q.front();
                q.pop_front();
                choice = 1 - choice;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);  
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}