#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

vector<ll> lis(vector<ll>& v) { // 1-index
    ll n = v.size() - 1;
    vector<ll> byLen(v.size() + 1, 1e9);
    vector<ll> ans(v.size() + 1);
    vector<ll> idByLen(v.size() + 1, 1e9);
    byLen[0] = 0;

    ans[1] = 1;
    byLen[1] = v[1];
    idByLen[1] = 1;
    ll mxId = 1;
    FOR(i, 2, n) {
        auto idx = prev(lower_bound(byLen.begin(), byLen.end(), v[i])) - byLen.begin();
        ans[i] = idx + 1;
        chkmin(byLen[ans[i]], v[i]);
        chkmin(idByLen[ans[i]], i);
        if (ans[i] > ans[mxId]) mxId = i;
    }

    vector<ll> r = {mxId};
    while (ans[r.back()] != 1) r.emplace_back(idByLen[ans[r.back()] - 1]);
    reverse(r.begin(), r.end());
    return r;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> p(n + 2, 0);
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<ll> inc = lis(p);
    reverse(p.begin(), p.end());
    vector<ll> dec = lis(p);
    
    for(int i = 0; i < dec.size(); i++){
        dec[i] = n - dec[i] + 1;
    }

    if(dec.back() != 1) dec.emplace_back(1);
    reverse(dec.begin(), dec.end()); 
    reverse(p.begin(), p.end());

    // for(int i = 0; i < inc.size(); i++) cout << inc[i] << " ";
    // cout << "\n";
    // for(int i = 0; i < dec.size(); i++) cout << dec[i] << " ";
    // cout << "\n";

    int idx = 1;
    ll ans = 0;
    // 右边
    for(int i = 0; i < dec.size(); i++){
        ans += p[dec[i]] * (dec[i] - idx);
        idx = dec[i];
    }

    idx = n;

    // 左边
    for(int i = dec.size() - 1; i >= 0; i--){
        ans += p[dec[i]] * (idx - dec[i]);
        idx = dec[i];
    }
    idx = 0;
    ll maxv = ans;
    for(int i = 1; i < inc.size(); i++){
        vector<int> affected;
        // remove all the influence of dec
        affected.emplace_back(inc[i - 1]);
        while(idx != dec.size() - 1 && dec[idx] < inc[i]){
            affected.emplace_back(dec[idx]);     
            idx++;
        }
        
        for(int j = 1; j < affected.size(); j++){
        /*  (prev)      (prev)
            inc[i - 1]  dec[idx]  dec[idx + 1] inc[i] dec[idx + 2]
        */
            // between dec[idx + 1] and dec[idx]
            // 左边
            ans -= p[affected[j - 1]] * ( affected[j] - affected[j - 1] );

            // 右边
            ans -= p[affected[j]] * ( affected[j] - affected[j - 1] );
        }
        // affected.emplace_back(inc[i]);
        ans -= p[dec[idx]] * (dec[idx] - affected.back());
        ans -= p[affected.back()] * (dec[idx] - affected.back());
        
        
        ans += p[inc[i - 1]] * (inc[i] - inc[i - 1]);
        ans += p[inc[i]] * (inc[i] - inc[i - 1]);
        ans += p[inc[i]] * (dec[idx] - inc[i]);
        ans += p[dec[idx]] * (dec[idx] - inc[i]);   

        maxv = max(maxv, ans);
        // cout << idx << " ";
        // cout << ans << "\n";
    }

    swap(inc, dec);
    for(int i = 0; i < inc.size(); i++) inc[i] = n - inc[i] + 1;
    for(int i = 0; i < dec.size(); i++) dec[i] = n - dec[i] + 1;
    reverse(inc.begin(), inc.end());
    reverse(dec.begin(), dec.end());
    reverse(p.begin(),p.end());

     idx = 1;
    ans = 0;
    // 右边
    for(int i = 0; i < dec.size(); i++){
        ans += p[dec[i]] * (dec[i] - idx);
        idx = dec[i];
    }

    idx = n;

    // 左边
    for(int i = dec.size() - 1; i >= 0; i--){
        ans += p[dec[i]] * (idx - dec[i]);
        idx = dec[i];
    }
    idx = 0;

    maxv = max(maxv, ans);
    for(int i = 1; i < inc.size(); i++){
        vector<int> affected;
        // remove all the influence of dec
        affected.emplace_back(inc[i - 1]);
        while(idx != dec.size() - 1 && dec[idx] < inc[i]){
            affected.emplace_back(dec[idx]);     
            idx++;
        }
        
        for(int j = 1; j < affected.size(); j++){
        /*  (prev)      (prev)
            inc[i - 1]  dec[idx]  dec[idx + 1] inc[i] dec[idx + 2]
        */
            // between dec[idx + 1] and dec[idx]
            // 左边
            ans -= p[affected[j - 1]] * ( affected[j] - affected[j - 1] );

            // 右边
            ans -= p[affected[j]] * ( affected[j] - affected[j - 1] );
        }
        // affected.emplace_back(inc[i]);
        ans -= p[dec[idx]] * (dec[idx] - affected.back());
        ans -= p[affected.back()] * (dec[idx] - affected.back());
        
        
        ans += p[inc[i - 1]] * (inc[i] - inc[i - 1]);
        ans += p[inc[i]] * (inc[i] - inc[i - 1]);
        ans += p[inc[i]] * (dec[idx] - inc[i]);
        ans += p[dec[idx]] * (dec[idx] - inc[i]);   

        maxv = max(maxv, ans);
        // cout << idx << " ";
        // cout << ans << "\n";
    }
    
    cout << maxv << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}