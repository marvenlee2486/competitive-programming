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
const ll N = 1e6+2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

struct seg{
    int l,r;
    seg(int l,int r):l(l),r(r){}
};

void solve(){
    int n;
    cin >> n;
    ll ori[n];
    ii a[n];
    rep(i,0,n) {
        ll x;
        cin >>x;
        a[i] = ii(x,i+1);
        ori[i]=x;
    }

    ll dp[n+2][2];
    ll ad[n+2][2];
    ll parent[n+2];
    FILL(parent,-1);
    FILL(dp,0);
    FILL(ad,0);
    vector<seg> sii;
    sort(a,a+n);
    rep(i,0,n){
        int idx,_;
        tie(_,idx) = a[i];
        
        if( parent[idx-1]==-1 && parent[idx+1] == -1){
            parent[idx] = sii.size();
            sii.push_back(seg(idx,idx));
            dp[idx][0]+=1;
            dp[idx+1][0]-=1;
            
        }
        else if (parent[idx-1]==-1){
            parent[idx] = parent[idx+1];
            sii[parent[idx]].l = idx;
            seg s = sii[parent[idx]];

            dp[s.r][1] += 1;
            dp[s.l -1][1] -= s.r-s.l+1;
            ad[s.r][1] += 1;
            ad[s.l][1] -=1;
        }
        else if (parent[idx+1] == -1){
            parent[idx] = parent[idx-1];
            sii[parent[idx]].r = idx;
            seg s = sii[parent[idx]];

            dp[s.l][0] +=1;
            dp[s.r+1][0] -= s.r-s.l+1;
            ad[s.l][0] += 1;
            ad[s.r][0] -=1;
        }
        else{
            int nr = sii[parent[idx+1]].r;
            sii[parent[idx-1]].r = nr;
            parent[nr] = parent[idx-1];
            seg s = sii[parent[idx-1]];
            dp[s.l][0] +=  nr - idx +1;
            dp[idx+1][0] -= (nr - idx+1)*(idx-s.l+1);
            ad[s.l][0] += nr - idx+1;
            ad[idx][0] -= nr - idx+1;


            dp[idx][1] -= (idx-s.l+1)*(nr - idx);
            dp[nr][1] += idx-s.l+1;
            ad[nr][1] += nr-idx;
            ad[idx+1][1] -= nr-idx;
        }
        
    }
    
    ll ans=0;
    ll cur=0;
    ll add=0;
    rep(i,0,n+2){
        cur +=dp[i][0];
        
        cur += add;
        add +=ad[i][0];
        
        cout << cur << " " << add << " " ;
        if(i>=1 && i<=n) ans += cur*ori[i-1];
        cout << ans << "\n";
        ans %=MOD;
    }
    cur =0;
    add =0;
    
    rrep(i,n+1,0){
        cur +=dp[i][1];
        
        cur += add;
        add +=ad[i][1];
        if(i>=1 && i<=n) ans += cur*ori[i-1];
        ans %= MOD;
    }
    cout << ans;

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin >> t;
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
