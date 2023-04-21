#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
using vl = vector<ll>;

#define rep(i,a,b) for(int i = (a); i < (b); i++)

void solve(){
    int n,m;
    cin >> n >> m;
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pq.push(-x);
    }

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        pq.pop();
        pq.push(-x);
    }

    ll sum  = 0;
    while(!pq.empty()){
        sum += -1*pq.top();
        pq.pop();
    }
    cout << sum << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}