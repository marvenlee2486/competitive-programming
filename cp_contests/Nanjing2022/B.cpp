#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const ll INF = 1e9;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 2);
    vector<ll> dpl(n + 2);
    vector<ll> dpr(n + 2);


    for(int i = 1; i <= n; i++) cin >> a[i];
    string s;
    cin >> s;
    s = "1" + s + "1";

    dpl[0] = 0;
    deque<ii> st;
    st.emplace_back(0,0);
    for(int i = 1; i <= n + 1; i++){
        while(st.front().second < i - k) st.pop_front();
        dpl[i] = st.front().first + a[i];
        if(s[i] == '1') st.clear();
        while(!st.empty() && st.back().first >= dpl[i]) st.pop_back();
        st.emplace_back(dpl[i], i);
    }

    dpr[n + 1] = 0;
    st.clear();
    st.emplace_back(0, n + 1);
    for(int i = n; i >= 0; i--){
        while(st.front().second  > i + k) st.pop_front();
        dpr[i] = st.front().first + a[i];
        if(s[i] == '1') st.clear();
        while(!st.empty() && st.back().first >= dpr[i]) st.pop_back();
        st.emplace_back(dpr[i], i);
    }

    // for(int i = 0; i <= n + 1; i++){
    //     cout << dpl[i] << " " << dpr[i] << " ";
    //     cout << dpl[i] + dpr[i] - a[i] << "\n";
    // }
    // cout << "\n";

    int q;
    cin >> q;
    while(q--){
        ll p,v, minv = INF * INF, cur;
        cin >> p >> v;
        st.clear();
        for(int i = max(p - k, 0ll); i <= min(p + k, n + 1ll); i++){

            while(!st.empty() && st.front().second < i - k) st.pop_front();
            cur = (i < p)? dpl[i]: st.front().first + ((i == p)?v:a[i]);
            if(s[i] == '1') st.clear();
            while(!st.empty() && st.back().first >= cur) st.pop_back();
            st.emplace_back(cur, i);
            
            // cout << i << ": " <<  cur << " " << dpr[i] << " " << cur + dpr[i] - a[i] << '\n';
            if(i >= p) minv = min(minv, cur + dpr[i] - a[i]);
        }
        st.clear();
        for(int i = min(p + k, n + 1ll); i >= max(p - k, 0ll); i--){
            while(!st.empty() && st.front().second  > i + k) st.pop_front();
            cur = (i > p)? dpr[i]: st.front().first + ((i == p)?v:a[i]);
            if(s[i] == '1') st.clear();
            while(!st.empty() && st.back().first >= cur) st.pop_back();
            st.emplace_back(cur, i);
            // cout << i << ": " <<  dpl[i] << " " << cur << " " << cur + dpl[i] - a[i] << '\n';
            
            if(i <= p) minv = min(minv, cur + dpl[i] - a[i]);
        }
        cout << minv << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}