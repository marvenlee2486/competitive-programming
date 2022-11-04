#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> ii;

class SuffixArray{
    private:
        ll max_range = 256;
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
            }
        }
    public:
        vl rank, sa, lcp; // 0 - index lcp in sa form between me and previous
        string s;
        bool cyclic = false;
        SuffixArray(string s, bool cyclic):cyclic(cyclic){
            if(!cyclic) s+= '\0';
            this->s = s;
            n = s.size();
            max_range = max(max_range,n);
            constructSA();
            constructLCP();
        }

};

SuffixArray* sa;
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
}

bool compare(pair<string,int> a, pair<string,int> b){return ( 
        a.first.length() < b.first.length() || 
        (a.first.length() == b.first.length() && a<b) ||
        (a.first.length() == b.first.length() && a==b && a.second <  b.second )
         );}
void solve(){
    vector<pair<string,int>> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s1; cin >> s1;
        s.emplace_back(s1,i+1);
    }
    sort(s.begin(),s.end(),compare);

    string s1 = "";
    map<int,int> owner;
    for(int i = s.size()-1; i >= 0; i--){
        owner[s1.size()] = i;
        s1 += s[i].first + '$';
    }
    // cout << s1 << "\n";
    sa = new SuffixArray( s1 ,true);
    vector<Vertex*> roots;
    int tl = 0, tr = s1.size();
    roots.push_back(build(tl, tr));
    for (int i = 0; i < s1.size(); i++) {
        int idx = sa->sa[i];
        auto it = owner.upper_bound(idx);
        it--;
        roots.push_back(update(roots.back(), tl, tr, it->second));
        //cout << i << " " << idx << " " << it->second << "\n";
    }

    int q;
    cin >> q;
    while(q--){
        string query;
        cin >> query;
        int l = 1, r = s1.size();
        // for(int i = 1; i <= s1.size(); i++){
        //     cout << i << " " << s1[sa->sa[i]] << "\n";
        // }
        while(l<r){
            int mid = (l+r)/2;
            //cout << mid << " " << s1.substr(sa->sa[mid], query.size()) << "\n";
            if( query <= s1.substr(sa->sa[mid], query.size())) r = mid;
            else l = mid +1;
        }
        if( l == s1.size() || s1.substr(sa->sa[l],query.size())!=query ){
            cout << "-1\n";
            continue;
        }

        int l2 = l, r2 = s1.size();
        while(l2<r2){
            int mid = (l2+r2)/2;
            // cout << mid << " " << s1.substr(sa->sa[mid], query.size()) << "\n";
            if( s1.substr(sa->sa[mid], query.size()) <= query ) l2 = mid+1;
            else r2 = mid;
        }
        r = l2-1;

        //cout << l << " " << r  << "\n";
        set<int> ans;
        int cnt = 0;
        int k = 1;
        while(k<=10 && cnt <= (r-l+1)){
            cnt++;
            int ret = find_kth(roots[l], roots[r+1], tl, tr, cnt);
            //cout << cnt << " " << k << " "<< ret << "\n";
            if(ans.find(ret) != ans.end()) continue;
            if(ret >= s.size()) break;
            ans.insert(ret);
            if(k!=1) cout << " ";
            cout << s[ret].second;
            k++;
        }
        // for(int i = l; i <= r ; i++){
        //     if(ans.size()==10) break;
        //     int idx = sa->sa[i];
        //     auto it = owner.upper_bound(idx);
        //     it--;
        //     if(ans.find(it->second) != ans.end()) continue;
        //     ans.insert(it->second);
        //     cout << s[it->second].second << " ";
        // }
        cout << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}