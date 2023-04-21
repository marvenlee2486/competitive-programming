#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using ll = long long;
const int INF = 1e9;
const int MAXN = 2000001;
int prime[MAXN];
ll ans[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 4; i < MAXN; i+= 2) prime[i] = 1;
    prime[1] = 1;
    for(int i = 3; i < MAXN; i+= 2){
        if(prime[i]) continue;
        
        int j = i * 2;
        while(j < MAXN){
            prime[j] = 1;
            j += i;
        }
    }
    
    for(ll i = 1; i < MAXN; i++){
        ll j = i * i;
        ll cnt = i;
        while(j < MAXN){
            ans[j] += prime[i] + prime[cnt] - (i==cnt && prime[i]==1);
            cnt++;
            j += i;
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        int i;
        cin >> i;
        cout << ans[i] << "\n";
    }
}