#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
#define all(x) x.begin(),x.end()
#define FOR(i, a, b) for (ll i = a; i <= b; ++i) 
#define chkmax(x, a) x = max(x, a)

struct SparseTable {
    using T = ll;
    using VT = vector<T>;
    using VVT = vector<vector<T>>;
    using func_type = function<T(const T&, const T&)>;

    VVT ST;
    vector<ll> lg;
    VT vv;
    static T default_func(const T& T1, const T& T2) {
        return max(T1, T2);
    }
    func_type op;

public:
    SparseTable(const vector<T>& v, func_type _func = default_func): op(_func) {
        int len = v.size(), k = ceil(log2(len)) + 1;
        ST.assign(k, VT(len, 0));
        for (int i = 0; i < v.size(); ++i) ST[0][i] = v[i];

        for (int i = 1; i < k; ++i) {
            for (int j = 0; j + (1 << i) <= len; j ++) {
                ST[i][j] = op(ST[i - 1][j], ST[i - 1][j + (1ll << (i - 1))]);
            }
        }
        vv = v ;        
        lg.assign(len + 1, 0);
        for (ll i = 2; i <= len; ++i) lg[i] = lg[i / 2] + 1;
    }
    
    T query(ll l, ll r) {
        int q = lg[r - l + 1];
        // cout << q << "\n";
        if(l == r) return vv[l];
        return op(ST[q][l], ST[q][r - (1 << q) + 1]);
    }
};
/*
9 30
algorithm
contest
eindhoven
icpc
nwerc
programming
regional
reykjavik
ru

*/
void solve(){
    int n,w;
    cin >> n >> w;
    vector<string> s(n+1);
    vector<ll> a(n+1);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        a[i] = s[i].size();
    }
     SparseTable st(a);
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j<=i; j++) 
    //     cout << i << " " << j << " " << st.query(j,i+1) << "\n";
    // }
    ll dp[n+1];
    ll l = 1, r = n;
    while(l<r){
        int m = (l + r)/2;

        dp[0] = w;
        for(int i = 1; i <= n;i++){
            dp[i] = -3;
            for(int j = i-1; j >= max(0,i-m); j--){
                dp[i] = max(dp[i],dp[j] - st.query(j+1,i) - 1);
            }
        }
        // cout << m << " " << dp[n] << "\n";
        if(dp[n] >= -1){
            r = m;
        }
        else{
            l = m+1;
        }

    }
    // cout << l << endl;
    vector<int> startEnd(n + 2);
    for(int i = 1; i <= n;i++) {
        dp[i] = -3;
        for(int j = i-1; j >= max(0ll,i-l); j--){
            ll val = dp[j] - st.query(j+1,i) - 1;
            if (val >= dp[i]) dp[i] = val, startEnd[i] = j + 1;
        }
    }

    ll j = n;
    vector<int> breakpoint;
    vector<int> col;
    while (j != 0) {
        col.emplace_back(st.query(startEnd[j],j));
        //cout << startEnd[j] << " " << j << " " << st.query(startEnd[j],j) <<'\n';
        breakpoint.emplace_back(j);
        j = startEnd[j] - 1;
    }
    reverse(col.begin(),col.end());
    reverse(breakpoint.begin(),breakpoint.end());
    vector<vector<string> > output(r,vector<string>());
     r = l;
    int idx = 0;
    int rcnt = 0;
    for(int i = 1 ; i <= n; i++){
        output[rcnt].emplace_back(s[i]);
        rcnt++;


        if(breakpoint[idx] == i){
            while(rcnt != r) {output[rcnt].emplace_back(""); rcnt++;}
            idx++;
            rcnt=0;
        }
    }
    cout << r << " " << col.size() << "\n";
    for(int cc : col) cout << cc << " ";
    cout << "\n";

    for (auto& c: output) { 
        FOR(i, 0, (signed)c.size() - 1) {
            cout << left << setw(col[i]) << setfill(' ') << c[i] << " "; 
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}