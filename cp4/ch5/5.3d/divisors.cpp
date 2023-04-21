#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3;
vector<int> prime;

void sieve(){
    bitset<MAXN> bs;

    bs.reset();
    prime.emplace_back(2);

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,k;
    sieve();
    while(cin >> n >> k){
        unordered_map<int,int> mp;
        for(int val = 2; val <= n; val++){
            int v = val;
            for(int p: prime){
                if(p > sqrt(v)) break;
                
                while(v % p == 0){
                    if(mp.find(p) == mp.end()) mp[p] = 0;
                    mp[p]++;

                    v /= p;
                }
            }
            if(v != 1) {
                if(mp.find(v) == mp.end()) mp[v] = 0;
                mp[v]++;
            }
        }

        for(int val = 2; val <= k; val++){
            int v = val;
            for(int p: prime){
                if(p > sqrt(v)) break;
                
                while(v % p == 0){
                    v /= p;
                    mp[p]--;
                }
            }
            if(v != 1) {
                mp[v]--;
            }
        }

        for(int val = 2; val <= n - k; val++){
            int v = val;
            for(int p: prime){
                if(p > sqrt(v)) break;
                
                while(v % p == 0){
                    v /= p;
                    mp[p]--;
                }
            }
            if(v != 1) {
                mp[v]--;
            }
        }

        long long ans = 1;
        for(auto&[p,cnt]:mp){
            //cout << p << " " << cnt << "\n";
            ans *= (long long)(cnt + 1);
        }
        cout << ans << "\n";
    }
}