#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
struct trie{
    trie* nxt[2];
    trie(){nxt[0] = NULL, nxt[1] = NULL;};
};
string convert(int x){
    string ret = "";
    for(int i = 0; i < 32; i++){
        ret += '0' + x % 2;
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void insert(trie* root, int x){
    trie* cur = root;
    string ret = convert(x);
    for(char c: ret){  
        if(cur->nxt[c - '0'] == NULL) cur->nxt[c - '0'] = new trie();
        cur = cur->nxt[c - '0'];
    }
}

int greatest(trie* root, int x){
    trie* cur = root;
    string ret = convert(x);
    int res = 0;
    // cout << x << " " << ret << "\n";
    for(char c: ret){
        res *= 2;
        if(cur->nxt[1 - c + '0']){
            res += 1;
            cur = cur->nxt[1 - c + '0'];
        }
        else{
            cur = cur->nxt[c - '0'];
        }
    }
    return res;
}

template <typename T>
class SparseTable {
  using VT = vector<T>;
  using VVT = vector<VT>;
  using func_type = function<T(const T &, const T &)>;

  VVT ST;
  vector<int> lg;
  static T default_func(const T &t1, const T &t2) { return max(t1, t2); }

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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    vector<int> prefix(n + 1, 0);
    unordered_map<int, vector<int> > order;
    int maxv = -1, st = 0;
    vector<ii> as;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = prefix[i - 1] ^ a[i];
        if(a[i] > maxv) {
            maxv = a[i];
            st = i;
        }
        order[a[i]].emplace_back(i);
    }
    SparseTable<int>* ST = new SparseTable<int>(a);


    function<pair<int,trie*>(int,int,int)> dnc = [&](int l, int r, int m)->pair<int,trie*> {
        if(l >= r){
            // cout << m << "\n";
            trie* ret = new trie();
            insert(ret, prefix[m]);
            
            // cout << ret << "\n";
            return {0,ret};
        }
        // cout << l << " " << r << " " << m << "\n";
        int maxl,maxr;
        trie* tl;
        trie* tr;
        if(l != m){
            int vall = ST->query(l, m - 1);
            auto it = lower_bound(order[vall].begin(), order[vall].end(), m);
            it--;
            tie(maxl, tl) = dnc(l, m - 1, *it);
        }
        else{
            tie(maxl, tl) = dnc(m, m, m);
        }

        if(r != m){
            int valr = ST->query(m + 1, r);
            auto it = upper_bound(order[valr].begin(), order[valr].end(), m);
            tie(maxr, tr) = dnc(m + 1, r, *it);
        }
        else{
            tie(maxr, tr) = dnc(m, m, m);
        }
        
        // cout << tl << " " << tr << "\n";
        int maxv = max(maxl, maxr);
        // cout << l << " " << r << " " << m << " " << maxv << "\n";


        // left is smaller
        if(r - m >= m - l){
            
            // cout << greatest(tr, 0) << "\n";
            for(int i = l; i <= m; i++) {
                // cout << i << " : " << max(greatest(tr, prefix[i - 1] ^ a[m]),prefix[m - 1] ^ prefix[i - 1]) << "\n";
                maxv = max(maxv,max(greatest(tr, prefix[i - 1] ^ a[m]),prefix[m - 1] ^ prefix[i - 1]));
            }
            for(int i = l; i <= m; i++) insert(tr,prefix[i]);
            return {maxv, tr};
        }
        // right is smaller
        else{
            
                // cout << greatest(tl, 0) << "\n";
            for(int i = m; i <= r; i++) {
                //cout << i << " : " << (prefix[i] ^ prefix[l - 1] ^ a[m]) << "\n";
                maxv = max(maxv ,max(greatest(tl, prefix[i] ^ a[m]), prefix[i] ^ prefix[l - 1] ^ a[m]));
            }
            for(int i = m; i <= r; i++) insert(tl,prefix[i]);
            return {maxv, tl};
        }
        
    };
    auto[ans, _] = dnc(1, n, st);
    cout << ans << "\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}