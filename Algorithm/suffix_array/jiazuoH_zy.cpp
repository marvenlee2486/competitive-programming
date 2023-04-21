// https://codeforces.com/group/aGASzy6kjB/contest/406605/problem/H
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> ii;
typedef vl vi;
class SuffixArray{
    private:
        ll max_range = 1e6+2;
        ll n;
        void countingSort(int k){
            vl freq(max_range,0);
            for (int i = 0; i < n; ++i)                     // count the frequency
                freq[ i + k < n ? rank[i+k] : 0]++;         // of each integer rank
            for (int i = 0, sum = 0; i < max_range; ++i) {
                int t = freq[i]; 
                freq[i] = sum;
                sum += t;
            }
            vl tempsa(n);
            for (int i = 0; i < n; ++i)                        // sort SA
            tempsa[ freq[ sa[i]+k < n ? rank[sa[i]+k] : 0] ++ ] = sa[i];
            swap(sa, tempsa);                                   // update SA
        }

        void constructLCP(){
            vl phi(n);
            vl plcp(n);
            phi[sa[0]] = -1;
            for(int i = 1; i < n; i++)
                phi[sa[i]] = sa[i-1];
            
            for(int i = 0, l = 0; i < n; i ++ ){
                if(phi[i] == -1){
                    plcp[i] = 0;
                    continue;
                }
                while((i+l < n ) && (phi[i] + l < n) && s[i+l] == s[phi[i] + l] ) l++;
                plcp[i] = l;
                l = max(l-1,0);
            }
            lcp.resize(n);
            //lcpsa.resize(n);
            for(int i = 0; i < n; i++)
                lcp[i] = plcp[sa[i]];

            // for(int i = 0; i < n; i++)
            //     lcpsa[rank[i]] = lcp[i];
        }

        void constructSA() {                           
            // init
            rank.assign(n,0);
            sa.assign(n,0);
            iota(sa.begin(), sa.end(), 0);               // the initial SA
            for (int i = 0; i < n; ++i) rank[i] = s[i];    // initial rankings
            
            
            for (int k = 1; k < n; k <<= 1) {            // repeat log_2 n times
                // this is actually radix sort
                countingSort(k);                           // sort by 2nd item
                countingSort(0);                           // stable-sort by 1st item
                vl temprank(n);
                int r = 0;
                temprank[sa[0]] = r;                         // re-ranking process
                for (int i = 1; i < n; ++i)                // compare adj suffixes
                    temprank[sa[i]] = // same pair => same rank r; otherwise, increase r
                    ((rank[sa[i]] == rank[sa[i-1]]) && (rank[sa[i]+k] == rank[sa[i-1]+k])) ?
                        r : ++r;
                swap(rank, temprank);                          // update RA
                if (rank[sa[n-1]] == n-1) break;             // nice optimization
                // max_range = min(max_range,(ll)r+1);
            }
        }
        
    public:
        vl rank, sa, lcp, owner; // 0 - index lcp in sa form between me and previous
        vector<ll> s;
        SuffixArray(vector<ll> s){
            this->s = s;
            n = s.size();
            constructSA();
            constructLCP();
        }

        // int lower_bound(string q){
        //     int l = 1, r = n;
        //     while(l<r){
        //         int m = (l+r)/2;
        //         //cout << m << " " << q << " " << compare(sa[m],q) << "\n";
        //         if(compare(sa[m],q)>=0) r = m;
        //         else l = m + 1;
        //     }
        //     return (l!=n)? sa[l]: -1;
        // }

        // int upper_bound(string q){
        //     int l = 1, r= n;
        //     while(l < r){
        //         int m = (l + r)/2;

        //         if(compare(sa[m], q) > 0) r = m;
        //         else l = m + 1;
        //     }
        //     return (l!=n)? sa[l] : -1;
        // }

        // int compare(int idx, string q){
        //     for(int i = 0; i < q.size(); i++){ 
        //         // if(idx+i == s.size()) return -1;
        //         if(s[idx+i] < q[i]) return -1;
        //         else if(s[idx+i] > q[i]) return 1;
        //     }
        //     return 0;
        // }

};


struct LazySegmentTree {
    using Z = ll;
    ll maxn;
    struct segt {
        ll l, r;
        Z ans;
        Z tag;
        bool hasTag;
    };
    vector<segt> T;

    LazySegmentTree(int n): maxn(n) { // confirm this is enough over ALL test case.
        T.resize(maxn << 2);
    }

    segt combine(segt l, segt r) {  // combine sets ddl to empty
        segt res;
        res.l = l.l, res.r = r.r, res.tag = res.hasTag = 0;
        res.ans = l.ans + r.ans; // TODO
        return res; 
    }

    void pushTag(ll o) { // TODO
        Z& tg = T[o].tag;
        if (T[o].l != T[o].r && T[o].hasTag) {
            T[o << 1].tag = tg,
                T[o << 1].ans = tg * (T[o << 1].r - T[o << 1].l + 1),
                T[o << 1].hasTag = 1;
            T[o << 1 | 1].tag = tg,
                    T[o << 1 | 1].ans =
                        tg * (T[o << 1 | 1].r - T[o << 1 | 1].l + 1),
                    T[o << 1 | 1].hasTag = 1;
        }
        T[o].hasTag = 0;
    }

    void build(ll o, ll l, ll r) {
        T[o].l = l, T[o].r = r, T[o].hasTag = 0;  // TODO
        T[o].tag = T[o].ans = 0;
        if (l == r){
            T[o].ans = 0;
            return; // TODO
        }
        else {
            ll m = (l + r) >> 1;
            build(o << 1, l, m), build(o << 1 | 1, m + 1, r);
            T[o] = combine(T[o << 1], T[o << 1 | 1]);
        }
    }

    segt query(ll o, ll l, ll r) {
        pushTag(o);
        if (l > r) { // TODO
            assert(false);
            segt empty; empty.ans = 0;
            return empty;
        }

        if (T[o].l == l && T[o].r == r) return T[o];
        else {
            ll m = (T[o].l + T[o].r) >> 1;
            if (r <= m) return query(o << 1, l, r);
            else if (l >= m + 1) return query(o << 1 | 1, l, r);
            return combine(query(o << 1, l, m), query(o << 1 | 1, m + 1, r));
        }
    }

    void update(ll o, ll l, ll r, Z dx) {
        pushTag(o);
        if (T[o].l == l && T[o].r == r) T[o].ans = dx; // TODO
        else {
            ll m = (T[o].l + T[o].r) >> 1;
            if (r <= m)
                update(o << 1, l, r, dx);
            else if (l >= m + 1)
                update(o << 1 | 1, l, r, dx);
            else
                update(o << 1, l, m, dx), update(o << 1 | 1, m + 1, r, dx);
            T[o] = combine(T[o << 1], T[o << 1 | 1]);
        }
    }
};

void solve(){
    int n;
    cin >> n;
    vl a(n,0);
    for(int i = 0; i < n; i++) cin >> a[i];
    vl l(n,0);
    vl r(n,n-1);
    // monotonic stack to find the left and right O(N)
    stack<ii> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[i] > st.top().first){
            st.pop();
        }
        if(!st.empty()) l[i] = st.top().second + 1;
        st.push(ii(a[i],i));
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && a[i] > st.top().first){
            st.pop();
        }
        if(!st.empty()) r[i] = st.top().second - 1;
        st.push(ii(a[i],i));
    }

    a.push_back(0);
    SuffixArray SA(a);
    // Initial Empty Segment Tree
    LazySegmentTree segt(n+3);
    segt.build(1,1,n+3);
    // Precompute all the required range O(n log n)
    vector<ii> range; // left, right
    for(int i = 1; i <= n; i++){
        range.emplace_back(SA.sa[i], SA.sa[i] + SA.lcp[i]);
    }
    sort(range.begin(),range.end());
    reverse(range.begin(),range.end());
    
    // Find ans O(n log n)
    ll ans = 0;
    for(auto&[idx,st]:range){
        segt.update(1, l[idx]+1,r[idx]+1 ,a[idx]);
        cout << l[idx] + 1 << " " << r[idx] + 1 << " " << a[idx] << "\n";
        ans += segt.query(1,st+1,n).ans;
        for(int i = 0 ; i < n ; i ++ ) cout << segt.query(1,i+1,i+1).ans << ' ';
        cout << "\n";
    }
    cout << ans << "\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}