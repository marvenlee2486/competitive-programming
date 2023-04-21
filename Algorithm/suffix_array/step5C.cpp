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
        vl rank, sa, lcp, owner; // 0 - index lcp in sa form between me and previous
        string s;
        SuffixArray(string s){
            this->s = s;
            n = s.size();
            max_range = max(max_range,n);
            constructSA();
            constructLCP();
        }

        int lower_bound(string q){
            int l = 1, r = n;
            while(l<r){
                int m = (l+r)/2;
                //cout << m << " " << q << " " << compare(sa[m],q) << "\n";
                if(compare(sa[m],q)>=0) r = m;
                else l = m + 1;
            }
            return l;
        }

        int upper_bound(string q){
            int l = 1, r= n;
            while(l < r){
                int m = (l + r)/2;

                if(compare(sa[m], q) > 0) r = m;
                else l = m + 1;
            }
            return l;
        }

        int compare(int idx, string q){
            for(int i = 0; i < q.size(); i++){ 
                // if(idx+i == s.size()) return -1;
                if(s[idx+i] < q[i]) return -1;
                else if(s[idx+i] > q[i]) return 1;
            }
            return 0;
        }

};


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
            for(int j = 0; j + (1 << i) <= len; j++)
                ST[i][j] = op(ST[i-1][j], ST[i-1][j + (1 << (i-1))]);

        lg.assign(len+1,0);
        for(int i = 2; i <= len; i++) lg[i] = lg[i/2] + 1;

    }

    T query(int l, int r) {
        if(r<l || r > ST[0].size()){
            exit(0);
        }
        int q = lg[ r - l +1];
        return op(ST[q][l], ST[q][r - (1 << q) + 1]);
    }
};


int main(){
    string s;
    cin >> s;
    s += '\0';
    SuffixArray* sa = new SuffixArray(s);
    SparseTable<ll>* st = new SparseTable<ll>(sa->lcp);
    int n;
    cin >> n;
    vector<ii> arr;
    while(n--){
        int l,r;
        cin >> l >> r;
        arr.emplace_back(l-1,r-1);
    }

    sort(arr.begin(),arr.end(),[&](auto a, auto b){
        int idx_a = sa->rank[a.first];
        int idx_b = sa->rank[b.first];
        //cout << "DEBUG " <<  a.first << " " << a.second << " "  << b.first << " " << b.second << "\n";
        assert(idx_a == idx_b || min(idx_a, idx_b) < s.size() - 1 );
        if(idx_a < idx_b){
            //cout << st->query( idx_a+1, idx_b) << "\n";
            if(st->query( idx_a+1, idx_b)  >= b.second-b.first+1 ){
                return( a.second-a.first < b.second-b.first  || (a.second-a.first == b.second-b.first && a.first < b.first) );
            } else return true;
        }
        else if(idx_a == idx_b){
            return( a.second-a.first <= b.second-b.first);
        }
        else{
            if(st->query( idx_b +1, idx_a)  >= a.second-a.first+1 ){
                return !(b.second-b.first < a.second-a.first  || (b.second-b.first == a.second-a.first && b.first < a.first) );
            } else return false;
        }
    });

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first +1 << " " << arr[i].second + 1 << "\n";
    }

}