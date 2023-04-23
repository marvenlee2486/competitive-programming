#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s; 
    ll m;
    cin >> s >> m;
    ll n = s.size();
    vector<ll> idx[100];
    // int cnt[100];
    // memset(cnt, 0, sizeof cnt);
    
    for(int i = 0; i < n; i++)
        idx[s[i] - 33].emplace_back(i);
    ll ans = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            ll cnt = 0, icnt = 0, sumj = 0;
            if(idx[i].size() < 2 || idx[j].size() < 2) continue;
            if(i == j){
                char ss = 33 + i;
                ll total = 0;
                // cout << ss << "\n";
                ll ptri = 0, ptrj = 0;
                for(int ii = 1; ii < idx[i].size(); ii++){
                    // cout << cnt  << " ";
                    ans += cnt;
                    ptri++;
                    cnt += (idx[j][ptri] - 1) * total - sumj;
                    total += ptri;
                    sumj += ptri * idx[j][ptri];
                    ptrj ++;

                    total %= m;
                    cnt = (cnt % m + m ) % m;
                    ans %= m;
                    sumj %= m;
                }
                // cout << "\n";
            }else{
                ll ptri = 0, ptrj = 0;
                ll total = 0;
                while(ptri != idx[i].size()){
                    if(ptrj == idx[j].size() || idx[i][ptri] < idx[j][ptrj]){
                        ans += cnt;
                        ptri ++;
                    }else{
                        cnt += (idx[j][ptrj] - 1) * total - sumj;
                        total += ptri;
                        sumj += ptri * idx[j][ptrj];
                        ptrj ++;
                    }
                    total %= m;
                    cnt = (cnt % m + m ) % m;
                    ans %= m;
                    sumj %= m;
                }



            }
        }

    }
    cout << ans % m << "\n";

}