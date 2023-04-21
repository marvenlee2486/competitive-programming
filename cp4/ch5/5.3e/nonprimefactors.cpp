#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> prime;
const int N = 2 * 1e6 + 2;
ll ans[N];
void sieve(){
    const int MAXN = 2000;
    bitset<MAXN> bs;
    bs.reset();

    prime.emplace_back(2);

    for(int i = 3; i < MAXN; i += 2){
        if(bs[i]) continue;
        prime.emplace_back(i);
        int j = 2 * i;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }

    for(int i = 2; i < N; i++){
        ll pf = 0;
        ll f = 1;
        int n = i;
        for(int p : prime){
            if( p > sqrt(n)) break;
            ll cnt = 0;
            if( n % p == 0) pf++;
            while(n % p == 0){
                n /= p;
                cnt++;
            }
            f *= (cnt + 1);
        }
        if(n != 1) {
            f *= 2;
            pf ++;
        }
        ans[i] = f - pf;
    }
}

void solve(){
    int n;
    cin >> n;

    
    //cout << f << " " << pf  << " ";
    cout << ans[n] << "\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sieve();
    int q;
    cin >> q;
    while(q--) solve();
}