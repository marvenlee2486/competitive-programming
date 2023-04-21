#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5;
vector<ll> prime;
void sieve(){
    bitset<MAXN> bs;
    bs.reset();
    prime.emplace_back(2);
    for(int i = 3; i < MAXN; i+=2){
        if(bs[i]) continue;
        prime.emplace_back(i);
        int j = 2 * i;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }
}

int main(){
    ll n,m;
    sieve();
    while(cin >> n >> m){
        bool can = true;
        ll val = m;
        for(ll p: prime){
            if(p > sqrt(val)) break;
            ll cnt = 0;
            while(val % p == 0){
                val /= p;
                cnt++;
            }

            //cout << val << " " << p << " " << cnt << "\n";
            ll got = 0;
            ll pp = p;
            for(int i = 1; got < cnt && pp < n;i++){
                got += n/pp;
                pp *= p;
            }
            if(cnt > got) can = false;
        }
        // cout << val << " " << n << "\n";
        if(val > n) can = false;

        if(n == 0){
            if(m == 1) can = true;
            else can = false;
        }
        if(m == 0) can = false;
        if(can){
            cout << m << " divides " << n << "!\n";
        }
        else{
            cout << m << " does not divide " << n << "!\n";
        }
    }
}