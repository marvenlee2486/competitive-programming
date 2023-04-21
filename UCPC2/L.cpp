#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))                    // the key operation

using vll = vector<int>;
using vi = vector<int>;
using ll = long long; 
class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) {return rsq(j) - rsq(i-1); } // inc/exclusion

  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> number(n, 1);
    multiset<int> use;
    
    for(auto&i : a) cin >> i;
    for(auto&i : b) cin >> i;
    for(int i = 0; i < k; i++){
        int xx;
        cin >> xx;
        use.emplace(xx);
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        if(j < m && a[i] == b[j]) j++;
    }
    if(j != m){
        cout << "NO\n";
        return;
    }

    j = 0;

    // st = 1 mean not in b
    vector<int> left(n, 0);
    vector<int> right(n, n - 1);
    
    vector<pair<int,int> > st;
    for(int i = 0; i < n; i++){
        if(j < m && a[i] == b[j]) {
            while(!st.empty() && (-1 * st.back().first) < a[i]){
                st.pop_back();
            }
            if(!st.empty()) left[i] = st.back().second + 1;

            st.emplace_back(-1 * a[i], i);
            
            j++;
        } else{
            if(!st.empty()){
                auto it = lower_bound(st.begin(), st.end(), pair<int,int>( -1 * a[i], -1));

                if(it == st.begin()) continue;
                it--;
                left[i] = it->second + 1;
            }            
        }
    }
    st.clear();

    
    j = m - 1;
    for(int i = n - 1; i >= 0; i--){
        if(j >= 0 && a[i] == b[j]) {
            while(!st.empty() && (-1 * st.back().first) < a[i]){
                st.pop_back();
            }
            if(!st.empty()) right[i] = st.back().second - 1;

            st.emplace_back(-1 * a[i], i);
            
            j--;
        } else{
            if(!st.empty()){
                auto it = lower_bound(st.begin(), st.end(), pair<int,int>( -1 * a[i], -1));

                if(it == st.begin()) continue;
                it--;
                right[i] = it->second - 1;
            }            
        }
    }
    // for(int i = 0; i < n; i ++){
    //     cout << left[i] << " " << right[i] << "\n";
    // }
    // for(int i = n - 1; i >= 0; i--){
    //     while(!st.empty() && st.top().first < a[i]){
    //         st.pop();
    //     }
    //     if(!st.empty()) right[i] = st.top().second - 1;
    //     if(j >= 0 && a[i] == b[j]) {
    //         j--;
    //         st.emplace(a[i], i);
    //     }
    // }

    FenwickTree ft(n + 2, vector<int>(n + 2, 0));
    vector<pair<int,int> > asor;
    for(int i = 0; i < n; i++){
        asor.emplace_back(a[i],i); 
    }
    sort(asor.begin(),asor.end());
    reverse(asor.begin(),asor.end());
    for(auto[v,idx] : asor){
        // cout << idx << " " << left[idx] << " " << right[idx] << " ";
        // cout << ft.rsq(left[idx] + 1, right[idx] + 1) << "\n";
        number[idx] = right[idx] - left[idx] + 1 - ft.rsq(left[idx] + 1, right[idx] + 1);
        ft.update(idx + 1, 1);
    }
    
    // for(int i = 0; i < n; i++) cout << number[i] << " ";
    // cout << "\n";


    j = 0;
    vector<pair<int,int>> need;

    for(int i = 0; i < n; i++){
        if(j < m && a[i] == b[j]) j++;
        else{
            need.emplace_back(a[i],number[i]);
        }
    }
    sort(need.begin(),need.end());
    reverse(need.begin(), need.end());

    for(auto[_,val]: need){
        auto it = use.upper_bound(val);
        if(it == use.begin() || use.size() == 0){
            cout << "NO\n";
            return;
        }
        it--;
        use.erase(it);
    }

    cout << "YES\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}

/*
1
5 2
*/