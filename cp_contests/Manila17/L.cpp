#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(vector<ll>& a){
    int n = a.size();
    ll ans = 0;
    for(int i = 0 ; i < n; ++i){
        if(a[i] < 0) return -1;
        if(a[i] % 2 == 1){
            if(i + 2 < n){
                a[i]--, a[i+1]--, a[i+2] --;
                ans++;
            }else{
                return -1;
            }
        }
    }
    for(int i = 0 ; i < n; ++i){
        assert(a[i] >= 0);
        if(i + 2 < n){
            ll rev = min(a[i], min(a[i+1], a[i+2]));
            assert(rev %2 == 0);
            ans += rev ;
            a[i] -= rev;
            a[i+1] -= rev;
            a[i+2] -= rev;
        }
        ans += a[i] / 2;
    }
    return ans;
}
void solve2(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i: a){
        cin>>i;
    }
    auto b = a;
    reverse(b.begin(), b.end());
    auto x = solve(b), y = solve(a);
    if(x == -1 && y == -1){
        cout<<"no\n";
        return;
    }
    if(x == -1){
        cout<<y<<"\n";
    }else if(y == -1){
        cout<<x<<"\n";
    }else{
        cout<<min(x,y)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin>>_;
    while(_--){
        solve2();
    }
}