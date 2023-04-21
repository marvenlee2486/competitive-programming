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
        SuffixArray(string s){
            this->s = s;
            n = s.size();
            max_range = max(max_range,n);
            constructSA();
            constructLCP();
        }

};

SuffixArray* sa;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s += s + "$";
    sa = new SuffixArray(s);
    int idx = -1;
    for(int i = 0; i < s.size(); i ++) {
        // cout << sa->sa[i] << " ";
        // cout << s.substr(sa->sa[i], s.size()-sa->sa[i]) << "\n";
        if(sa->sa[i] < n){
            idx = sa->sa[i];
            break;
        }
    }
    for(int i = 0 ; i < n; i ++){
        if( idx == 2*n) idx = 0;
        cout << s[idx];
        idx++;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}