#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1002;
vector<int> prime;

void sieve(){
    prime.emplace_back(2);
    bitset<MAXN> bs;
    bs.reset();

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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sieve();
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> a(n, 0);
    vector<unordered_map<int,int> > mpcnt(n);
    int idx = 0;
    for(auto &i : a){
        cin >> i;
        int val = i;
        for(int p : prime){
            if(p > sqrt(val)) break;
            int cnt = 0;
            while(val % p == 0){
                if(mp.find(p) == mp.end()) mp[p] = 0;
                mp[p] += 1;
                val /= p;
                cnt++;
            }
            mpcnt[idx][p] = cnt;
        }
        mpcnt[idx][val] = 1;
        if(mp.find(val) == mp.end()) mp[val] = 0;
                mp[val] += 1;
        idx++;
    }
    int ans = 1;
    int c = 0;
    for(auto&[p, cnt] : mp){
        if(cnt < n || p == 1) continue;
        cnt /= n;
        ans *= pow(p, cnt);
        for(int i = 0; i < n; i++){
            if(mpcnt[i].find(p) == mpcnt[i].end()) mpcnt[i][p] = 0;
            if(mpcnt[i][p] < cnt) c += cnt - mpcnt[i][p];
        }
    }
    cout << ans << " " << c << "\n";
}