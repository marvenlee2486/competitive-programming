#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int phi[N];
void sieve(){
    vector<int> prime;
    prime.emplace_back(2);
    const int MAXN = 1e3;
    bitset<MAXN> bs;
    bs.reset();

    for(int i = 3; i < MAXN; i++){
        if(bs[i]) continue;
        prime.emplace_back(i);
        int j = 2 * i;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }
    phi[0] = 0;
    phi[1] = 2;
    for(int i = 2; i < N; i++){
        int res = i;
        int val = i;
        for(int p : prime){
            if(p > sqrt(val)) break;
            if(val % p == 0) res -= res/p;
            while( val % p == 0) val /= p;
        }
        if(val != 1) res -= res/val;
        phi[i] = res + phi[i - 1];
    }
}

void solve(){
    int n;
    cin >> n;
    cout << phi[n] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--){
        int k; cin >> k;
        cout << k << " ";
        solve();
    }
}