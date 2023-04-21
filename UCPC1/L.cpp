#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n, 0);
    vector<ll> b(m, 0);
    vector<ll> ca(n, 0);
    vector<ll> cb(m, 0);

    for(auto&i : a) cin >> i;
    for(auto&i : b) cin >> i;
    for(int i = 0; i < n; i++) ca[i] = a[i];
    for(int i = 0; i < m; i++) cb[i] = b[i];
    ld cnt1 = 0, cnt2 = 0, cnt0 = 0;
    
    int st = 0;
    function<void(int, int, int, int, int, ld)> dfs = [&](int u, int v, int s1, int s2, int turn, ld cur){
        int ub = __builtin_popcount(u);
        int vb = __builtin_popcount(v);
        // cout << cur << "\n";
        // cout << u << " " << v << " " << s1 << " " << s2 << " " << "\n";
        if(ub == 0 && vb == 0) cnt0 += cur;
        else if(ub == 0) cnt2 += cur;
        else if(vb == 0) cnt1 += cur;
        
        if(ub == 0 || vb == 0) return;

        if(s1 == n) s1 = 0;
        if(s2 == m) s2 = 0;
        while(((1 << s1) & u) == 0){
            s1++;
            if(s1 == n) s1 = 0; 
        } 
        while(((1 << s2) & v) == 0){
            s2++;
            if(s2 == m) s2 = 0;
        }
        if(turn == 1){    
            for(int i = 0; i < m; i++){
                if((v & (1 << i)) == 0) continue;
                int remu = u, remv = v, rema = ca[s1], remb = cb[i];
                ca[s1] -= b[i];
                cb[i] -= a[s1];

                if(ca[s1] <= 0) u -= (1 << s1);
                if(cb[i] <= 0) v -= (1 << i);

                dfs(u, v, s1 + 1, s2, 2, cur / vb);
                u = remu;
                v = remv;
                ca[s1] = rema;
                cb[i] = remb;
            }
        } 
        else if(turn == 2){
            for(int i = 0; i < n; i++){
                if( (u & (1 << i)) == 0) continue;
                int remu = u, remv = v, rema = ca[i], remb = cb[s2];
                ca[i] -= b[s2];
                cb[s2] -= a[i];

                if(ca[i] <= 0) u -= (1 << i);
                if(cb[s2] <= 0) v -= (1 << s2);

                dfs(u, v, s1, s2 + 1, 1, cur / ub);
                u = remu;
                v = remv;
                ca[i] = rema;
                cb[s2] = remb;
            }
        }
    
    };
    if(n > m) dfs( (1 << n) - 1, (1 << m) - 1, 0, 0, 1, 1);
    if(n < m) dfs( (1 << n) - 1, (1 << m) - 1, 0, 0, 2, 1);
    if(n == m){
        dfs( (1 << n) - 1, (1 << m) - 1, 0, 0, 1, 0.5);
        dfs( (1 << n) - 1, (1 << m) - 1, 0, 0, 2, 0.5);
    }
    cout << fixed << setprecision(15) << cnt1 << "\n" << cnt2 << "\n" << cnt0 << "\n";


}