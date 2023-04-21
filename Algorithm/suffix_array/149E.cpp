#include <bits/stdc++.h>
using namespace std;


template <typename T>
class SparseTable {
  using VT = vector<T>;
  using VVT = vector<VT>;
  using func_type = function<T(const T &, const T &)>;

  VVT ST;
  vector<int> lg;
  static T default_func(const T &t1, const T &t2) { return min(t1, t2); }

  func_type op;

 public:
    SparseTable(const vector<T> &v, func_type _func = default_func):op(_func){

        int len = v.size(), k = ceil(log2(len)) + 1;

        ST.assign(k, VT(len, 0));
        for(int i = 0; i < v.size(); i++) ST[0][i] = v[i];

        for(int i = 1; i < k ;i ++)
            for(int j = 0; j + (1 << i) < len; j++)
                ST[i][j] = op(ST[i-1][j], ST[i-1][j + (1 << (i-1))]);

        lg.assign(len+1,0);
        for(int i = 2; i <= len; i++) lg[i] = lg[i/2] + 1;

    }

    T query(int l, int r) {
        int q = lg[ r - l +1];
        return op(ST[q][l], ST[q][r - (1 << q) + 1]);
    }
};

typedef long long ll;
typedef vector<ll> vl;

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
        SuffixArray(string s){
            this->s = s;
            n = s.size();
            max_range = max(max_range,n);
            constructSA();
            constructLCP();
        }

};



ll lower_bound(string s, SuffixArray* sa){
    int l = 0, r = sa->s.size();
    while(l<r){
        int mid = (l+r)/2;

        int idx = sa->sa[mid];
        string get = sa->s.substr(idx, s.size());
        
        if(get < s) l = mid+1;
        else r = mid;
    }
    return l;
}

ll upper_bound(string s, SuffixArray* sa){
    int l = 0, r = sa->s.size();
    while(l<r){
        int mid = (l+r)/2;

        int idx = sa->sa[mid];
        string get = sa->s.substr(idx, s.size());

        if(get <= s) l = mid+1;
        else r = mid;
    }
    return l;
}

SuffixArray* sa1; 
SuffixArray* sa2;
SparseTable<ll>* st1;
SparseTable<ll>* st2;
void solve(){
    string s;
    cin >> s;
    

    sa1 = new SuffixArray(s + "$");
    reverse(s.begin(),s.end());
    sa2 = new SuffixArray(s + "$");
    reverse(s.begin(),s.end());

    // 1 - index
    st1 = new SparseTable<ll>(sa1->sa);
    st2 = new SparseTable<ll>(sa2->sa);


    int m, l1, l2 , r1, r2;
    int ans = 0;
    cin >> m;
    while(m--){
        string m;
        cin >> m;

        string suf="";
        string pre="";
        for(int i = m.size() - 1 ; i >= 0; i--){
            suf.push_back(m[i]);
        }
        bool can = false;
        for(int i = 1; i < m.size(); i++){
            pre.push_back(suf.back());
            suf.pop_back();

            l1 = lower_bound(pre,sa1);
            r1 = upper_bound(pre,sa1) - 1;

            l2 = lower_bound(suf,sa2);
            r2 = upper_bound(suf,sa2) - 1;
            if(r1 < l1 || r2 < l2) continue;
            
            int minv = st1->query(l1,r1);
            int maxv = s.size() - st2->query(l2,r2) - 1;
            if(maxv - minv +1 >= (int)m.size()){
                can = true;
                break;
            }
        }
        if(can) ans++;
    }
    cout << ans <<"\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}