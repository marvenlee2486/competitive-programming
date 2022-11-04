#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;


//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define repn(i,a,b) for(int i=(a);i<=(b);i++)
#define repin(i,a,b,x) for(int i=(a);i<(b);i+=x)
#define repnin(i,a,b,x) for(int i=(a);i<=(b);i+=x)
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define fbo find_by_order
#define ook order_of_key
#define ALL(v) v.begin(),v.end()
#define FILL(arr,x) memset(arr,x,sizeof arr);

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

ll mod(ll x, ll y = MOD) { return ((x % y) + y) % y; }

ll addm(ll x) { return x; }
template <typename... Ts> ll addm(ll x, Ts... ys) { return mod(x + addm(ys...)); }

ll mulm(ll x) { return x; }
template <typename... Ts> ll mulm(ll x, Ts... ys) { return mod(x * mulm(ys...)); }

const int MAXN = 1e6+2;
const int K = 21;
ll lg[MAXN+1];
ll st[MAXN][K + 1];

int rmq(int L, int R){
    ll j = lg[R - L + 1];
    ll maximum = max(st[L][j], st[R - (1 << j) + 1][j]);
    return maximum;
}

void solve(){
    
    int n;
    cin >> n;
    int N = n;
    ll a[n];
    ll ans=0;
    unordered_map<ll, vector<ll> > mpp;
    rep(i,0,n) {
        cin >> a[i];
        mpp[a[i]].push_back(i);
    }
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i/2] + 1;

    for (int i = 0; i < N; i++)
        st[i][0] = a[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    set<int> lowerbound;
    rep(val,1,MAXN){
        if(mpp.find(val)==mpp.end()) continue;

        vector<ll> loc = mpp[val];
        int rmb =1;
        int lower = lowerbound.lower_bound(loc[0]);
        for(int i=1;i<loc.size();i++){
            //cout << rmq(lower,loc[i])<< " ";
            if(rmq(lower,loc[i]) != val){
                //cout << "?? WHAT" << rmq(lower,loc[i]) << "\n";
                rmb = 1;
                lower = loc[i];
            } 
            else{
                //cout << "HELLO " << rmb << "\n";
                ans += rmb;
                rmb++;
            }
        }   
        cerr << val << " "  << ans << "\n";
        

        ll curi = val*2;
        while(curi < MAXN){
            if(mpp.find(curi)==mpp.end()){
                curi+=val;
                continue;
            }

            vector<ll> loc2 = mpp[curi];

            int ptr1 = 0;
            int ptr2 = 0;
            int rmbi = 0;
            int rmbm = 0;
            int prem = -1;
            // wang hou dui
            cerr << val << " " << curi << " " << ans << "\n";
            while( ptr2!=loc2.size()){
                // 2 is before 4;
                if(ptr1== loc.size()) ptr1= loc.size();
                if(ptr1 != loc.size() && loc[ptr1]<loc2[ptr2]){
                    // yes MAX is 4
                    if(rmq(loc[ptr1],loc2[ptr2]) == curi){
                        rmbi++;
                    }
                    else{
                        ans += rmbi;
                        rmbi = 0;
                    }
                    ptr1++;
                }
                else{
                    if(ptr1!=0 && rmq(loc[ptr1-1],loc2[ptr2]) == curi){
                        ans += rmbi;
                    } else{
                        rmbi=0;
                    }
                    ptr2++;
                }
            }
            cerr << "WANG HOU" << val << " " << curi << " " << ans << "\n";

            // wang qian dui
            ptr1= 0;
            ptr2 =0;
            rmbi =0;
            rmbm =0;
            while(ptr1 != loc.size()){
                // 2 is before 4
                if(ptr2==loc2.size()) ptr2=loc2.size();
                if(ptr2==loc2.size() || loc[ptr1]<loc2[ptr2]){
                    if(ptr2!=0 && rmq(loc2[ptr2-1], loc[ptr1])==curi  ){
                        ans += rmbm;
                    }
                    else{
                        rmbm = 0;
                    }
                    ptr1++;
                }
                // 4 is before 2
                else{
                    if(rmq(loc2[ptr2], loc[ptr1])==curi){
                        rmbm++;
                    }
                    else{
                        ans += rmbm;
                        rmbm = 0;
                    }
                    ptr2++;
                }
            }
            cerr << "WANGQIAN " << val << " " << curi << " " << ans << "\n";

            curi+=val;
            continue;
        }

        for(int v:loc){
            lowerbound.insert(v);
        }
        
    }
    cout << ans + n << "\n";

    

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t=1;
  cin >> t;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
