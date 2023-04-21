#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> prime;
const int N = 1e5;
ll d[N];
void sieve(){
    const int MAXN = 1e5;
    bitset<MAXN> bs;
    bs.reset();
    prime.push_back(2);
    for(int i = 3; i < MAXN; i+=2){
        if(bs[i]) continue;
        prime.emplace_back(i);
        int j = 2 * i;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }
    d[0] = 0;
    d[1] = 0;
    for(int i = 2; i < N; i++){
        int cnt = 0;
        int val = i;
        for(int p: prime){
            if(val % p == 0) cnt++;
            while(val % p == 0){
                val /= p;
            }
        }
        d[i] = cnt;
    }
}

int main(){
    sieve();

    int n; cin >> n;
    vector<int> a(n, 0);
    for(auto& i:a) cin >> i;
    
    ll dp[1 << n];
    ll rev[1 << n];
    for(int i = 0; i < (1<<n); i++){
        ll sum = 0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)) sum += a[j];
        }
        rev[i] = d[sum];
    }
    dp[0] = 0;
    for(int i = 0; i < (1<<n); i++){
        dp[i] = rev[i];
        for(int j = 1; j < i; j++){
            if( (i | j) != i) continue;
            dp[i] = max(dp[i], dp[j] + rev[i - j]);
        }
    } 
    cout << dp[(1 << n) - 1] << "\n";
} 