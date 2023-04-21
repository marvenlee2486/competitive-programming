#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll,ll,ll> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;


#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
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

const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 3*1e5+2;
class AC {
public:

int tot = 0;
struct Node{
    int next[26], ans, link, p;
    char pch;
    Node(int p):p(p){
        link = 0 , ans = 0;
        memset(next, 0,sizeof next);
    };
};
vector<Node> tr;

vector<int> dp;

AC(){
    tr.emplace_back(0);
}
// Trie
void insert(string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!tr[u].next[s[i] - '0']) 
            tr[u].next[s[i] - '0'] = ++tot, tr.emplace_back(u);  
        u = tr[u].next[s[i] - '0'];                      
    }
    tr[u].ans++;                                    
}

queue<int> q;
void build() {
    for (int i = 0; i < 26; i++)
        if (tr[0].next[i]) q.push(tr[0].next[i]);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (tr[u].next[i]) {
                tr[tr[u].next[i]].link = tr[tr[u].link].next[i];
                q.push(tr[u].next[i]);
            } 
            else tr[u].next[i] = tr[tr[u].link].next[i];
        }
    }
    dp.assign(tot+1,-1);
}

int dfs(int u){
    if(dp[u] != -1) return dp[u];
    if(u == 0) return dp[u] = 0;
    return dp[u] = dfs(tr[u].link) + tr[u].ans;
}

int query(string t) {
    int u = 0, res = 0;
    for (int i = 0; i < t.size(); i++) {
        u = tr[u].next[t[i] - '0'];
        res += dfs(u);
    }
    return res;
}
};


vector<AC> pattern(21);
 

void recursive(str s,int left, int x){

    if(left ==0){
        rep(i,1,x/2+1){
            if(x%i == 0){
                int v =0;
                for(char c:s){
                    v = pattern[i].tr[v].next[c-'0'];
                    if(pattern[i].tr[v].ans) return;
                }
            }
        }
        pattern[x].insert(s);
        return;
    }
    rep(i,1,min(left+1,10)){
        char add = '0' + i;
        recursive(s + add, left - i, x);
    }

}

int main()
{
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

    rep(x,1,21){
        recursive("",x,x);
        pattern[x].build();
    }

    str s;
    int x;
    cin >> s >> x;
    int dp[s.size()+1][pattern[x].tot+1];
    rep(i,0,s.size()+1){
        rep(j,0,pattern[x].tot+1) dp[i][j]= INF;
    }
    dp[0][0]=0;
    for(int i = 0; i<s.size(); i++ ){
        for(int v =0; v<pattern[x].tot+1; v++){
            MIN(dp[i+1][v], dp[i][v] +1);

            int nv = pattern[x].tr[v].next[s[i]-'0'];
            if(!pattern[x].tr[nv].ans){
                MIN(dp[i+1][nv], dp[i][v]);
            }
            
        }
        
    }
    int ans = INF;
    rep(v,0,pattern[x].tot+1) MIN(ans,dp[s.size()][v]);
    cout << ans;

  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

