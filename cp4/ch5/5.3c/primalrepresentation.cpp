#include<bits/stdc++.h>
using namespace std;
const int MAXN = 70000;
using ll = long long;
bitset<MAXN> bs;
vector<ll> prime;
void sieve(){
    bs.set();
    bs.reset(0);
    bs.reset(1);
    prime.emplace_back(2);
    for(int i = 4; i < MAXN; i+=2) bs.reset(i);

    for(int i = 3; i < MAXN; i+=2){
        if(!bs[i]) continue;
        prime.emplace_back(i);
        int j = 2 * i;
        while(j < MAXN){
            bs.reset(j);
            j += i;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sieve();
    // cout << "ASD\n";
    ll x;
    while(cin >> x){
        map<ll, ll> mp;
        if(x < 0){
            cout << "-1 ";
            x = -x;
        }
        int n = sqrt(x);
        for(int p: prime){
            if(p > x) break;
            
            while(x % p == 0){
                if(mp.find(p) == mp.end()) mp[p] = 0;
                mp[p]++;
                x/=p;
            }
        }
        if(x != 1){
            if(mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;

        }
        for(auto&[p,cnt]:mp){
            cout << p;
            if(cnt != 1) cout << "^" << cnt;
            cout << " ";
        }
        cout << "\n";
    }

}