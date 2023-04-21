#include<bits/stdc++.h>
using namespace std;
const int MAXN = 40000;
bitset<MAXN> bs;

void sieve(){
    bs.set();

    bs[0] = bs[1] = 0;
    for(int i = 4; i < MAXN; i+=2){
        bs.reset(i);
    }

    for(int i = 3; i < MAXN; i+=2){
        if(!bs[i]) continue;

        int j = i * 2;
        while(j < MAXN){
            bs.reset(j);
            j += i;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    if(n == 4) ans.emplace_back(2,2);
    for(int i = 3; i <= n/2; i += 2){
        if(bs[i] && bs[n - i]) ans.emplace_back(i,n - i);
    }
    cout << n << " has " <<  ans.size() << " representation(s)\n";
    for(auto[l,r]: ans) cout << l << "+" << r <<"\n"; 
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    sieve();
    while(t--) {
        solve();
        if(t) cout << "\n";
    }
}