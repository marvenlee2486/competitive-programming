#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
vector<int> prime;
using ll = long long;
void init(){
    bitset<MAXN> bs;
    prime.emplace_back(2);
    bs.reset();

    for(int i = 2; i < MAXN; i+= 2) bs.set(i);

    for(int i = 3; i < MAXN; i+= 2){
        if(bs[i]) continue;
        prime.emplace_back(i);
        int j = 2 * i;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    ll cnt[33];
    for(int i = 0; i < 33; i++) cnt[i] = 1;
    ll ans = 0;
    for(int p: prime){
        if(p > sqrt(n)) break;
        int cc = 0;
        while(n % p == 0){
            n /= p;
            cc++;
            cnt[cc] *= p;
        }
    }
    if(n != 1){
        cnt[1] *= n;
    }
    for(int i = 0; i < 33; i++){
        if(cnt[i] != 1) ans += cnt[i];
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}