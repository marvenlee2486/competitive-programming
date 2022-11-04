#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

typedef long long ll;
typedef vector<ll> vl;

class SuffixArray{
    private:
        const ll max_range = 256;
        int n;
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
        vl rank, sa;
        string s;
        SuffixArray(string s):s(s){
            n = s.size();
            constructSA();
        }
};


void solve() {
    int i ,p, m = 127, w;

    int n;
    string ss; cin >> ss;
    bool same = true;
    for(int i = 0; i <ss.size();i++){
        if(i==0 && ss[i]!=ss[ss.size()-1]) {
            same = false;
            break;
        }
        if(i!=0 && ss[i]!=ss[i-1]) {
            same = false;
            break;
        }
    }
    if(same) {
        cout << "1\n";
        return;
    }
    SuffixArray sa(ss);
    cout << sa.sa[0]+1 << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}