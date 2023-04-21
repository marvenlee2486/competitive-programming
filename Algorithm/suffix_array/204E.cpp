#include <bits/stdc++.h>
using namespace std;
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
        vl rank, sa, lcp, owner; // 0 - index lcp in sa form between me and previous
        string s;
        SuffixArray(string s){
            this->s = s;
            n = s.size();
            max_range = max(max_range,n);
            constructSA();
            constructLCP();
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
        int q = lg[ r - l +1];
        return op(ST[q][l], ST[q][r - (1 << q) + 1]);
    }
};

SuffixArray* sa;
SparseTable<ll>* st;

void solve(){
    int n, k;
    cin >> n >> k;
    
    string s = "";
    vector<ll> owner;
    vector<ll> end;
    vector<ll> rightmost;
    for(int i = 0; i < n; i++){
        string temp; cin >> temp;
        s += temp ;
        if(i!=n-1) s += "$";
        else s += '\0';
        end.push_back(s.size());
        for(int j = 0; j <= temp.size(); j++){
            owner.push_back(i);
        }
    }

    vector<ll> ans (n,0);
    sa = new SuffixArray(s);
    st = new SparseTable<ll>(sa->lcp);
    unordered_map<int,int > mp;
    int cnt = 0;
    int l = n;
    // for(int i = 0; i < s.size(); i ++){
    //   cout << sa->rank[i] << " ";
    // }
    // cout << "\n";
    rightmost.assign(s.size(),-1);
    for(int i = n; i < s.size(); i++){
        if(mp[owner[sa->sa[i]]] == 0){
            cnt++;
        }

        mp[owner[sa->sa[i]]]++;
        if(cnt == k) {
            rightmost[l] = i;
            
            mp[owner[sa->sa[l]]]--;
            while(mp[owner[sa->sa[l]]] != 0){
                l++;
                rightmost[l] = i;
                mp[owner[sa->sa[l]]]--;
            }
            cnt--;
            l++;
        }
    }
    // cout << s << "\n";
    for(int i = n; i < s.size(); i++){
        
        int idx = sa->sa[i];
        int len_l = 0, len_r = end[owner[idx]]-idx -1;
        // cout << idx << " " <<  s[idx] << " " << owner[idx] << "\n";
        while(len_l < len_r){
            int len = (len_l + len_r + 1)/2;
            int left_l = n, left_r = i, right_l = i, right_r = s.size() -1;
            while(left_l < left_r){
                int left = (left_l + left_r)/2;
                if( st->query(left + 1, i) >= len ) left_r = left;
                else left_l = left+1;
            }

            while(right_l < right_r){
                int right = (right_l + right_r + 1)/2;
                if( st->query(i + 1, right) >= len ) right_l = right;
                else right_r = right - 1;
            }

            // cout << left_l << " " <<  right_l << "\n";
            if(rightmost[left_l] != -1 && rightmost[left_l] <= right_l) len_l = len;
            else len_r = len - 1;
        }
        // cout << len_l << "DONE\n";
        ans[owner[idx]] += len_l;
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}