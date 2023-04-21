#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5;
vector<int> prime;
void sieve(){
    bitset<MAXN> bs;
    bs.reset();

    prime.emplace_back(2);
    for(int i = 3; i < MAXN; i += 2){
        if(bs[i]) continue;
        prime.emplace_back(i);
        int j = i * 2;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }
}

int main(){
    ll n;
    sieve();
    while(cin >> n){
        cout << n << " ";

        ll ans = 1;
        for(int p: prime){
            if(p > sqrt(n)) break;
            int cnt = 0;
            while(n % p == 0){
                cnt++;
                n /= p;
            }
            if(cnt > 1) ans *= pow(cnt , p);
        }
        cout << ans << "\n";
    }
}