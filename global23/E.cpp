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

ll mod(ll x, ll y = MOD) { return ((x % y) + y) % y; }

ll addm(ll x) { return x; }
template <typename... Ts> ll addm(ll x, Ts... ys) { return mod(x + addm(ys...)); }

ll mulm(ll x) { return x; }
template <typename... Ts> ll mulm(ll x, Ts... ys) { return mod(x * mulm(ys...)); }

bool q(set<int> x){
    cout << "? " << x.size();
    for(int y:x) cout << " " << y;
    cout << endl;
    string s; cin >> s;
    if(s=="NO") return false;
    else return true;
}


bool q(set<int> x, set<int> x2){
    cout << "? " << x.size() + x2.size();
    for(int y:x) cout << " " << y;
    for(int y:x2) cout << " " << y;
    cout << endl;
    string s; cin >> s;
    if(s=="NO") return false;
    else return true;
}

bool ans(int x){
    cout << "! "<<x<<endl;
    string s; cin >> s;
    if(s==":)") return true;
    else return false;
}
void solve(){
    int n;
    cin >> n;
    set<int> poss;
    for(int i=0;i<n;i++) poss.insert(i+1);
    while(poss.size()>=3){
        vector<set<int>> four(4);

        size_t i = 0;

        for (auto d : poss) 
            four[ (i++)%4].insert(d);
        poss.clear();
        bool q1= q(four[0],four[1]);
        bool q2= q(four[0],four[1]);
        
        if(q1==q2){
            if(q1) set_union(four[0].begin(), four[0].end(), four[1].begin(), four[1].end(), inserter(poss,poss.begin()));
            else set_union(four[2].begin(), four[2].end(), four[3].begin(), four[3].end(), inserter(poss,poss.begin()));
            continue;
        }

        bool q3 = q(four[0],four[2]);
        bool q4 = q(four[0],four[2]);

        if(q3==q4){
            if(q3) set_union(four[0].begin(), four[0].end(), four[2].begin(), four[2].end(), inserter(poss,poss.begin()));
            else set_union(four[1].begin(), four[1].end(), four[3].begin(), four[3].end(), inserter(poss,poss.begin()));
            continue;
        }

        bool q5 = q(four[1],four[2]);
        if(q1 && !q2 && q3 && !q4){
            // 0 3 2
            if(q5){
                set_union(four[2].begin(), four[2].end(), four[3].begin(), four[3].end(), inserter(poss,poss.begin()));
            }
            else {
                set_union(four[0].begin(), four[0].end(), four[3].begin(), four[3].end(), inserter(poss,poss.begin()));
            }
        }

        if(q1 && !q2 && !q3 && q4){
            // 1 2 3
            if(q5){
                set_union(four[1].begin(), four[1].end(), four[2].begin(), four[2].end(), inserter(poss,poss.begin()));
            }
            else {
                set_union(four[2].begin(), four[2].end(), four[3].begin(), four[3].end(), inserter(poss,poss.begin()));
            }
        }

        if(!q1 && q2 && q3 && !q4){
            //2 1 0
            if(q5){
                set_union(four[2].begin(), four[2].end(), four[1].begin(), four[1].end(), inserter(poss,poss.begin()));
            }
            else{
                set_union(four[0].begin(), four[0].end(), four[1].begin(), four[1].end(), inserter(poss,poss.begin()));
            }
        }

        if(!q1 && q2 && !q3 && q4){
            //3 0 1
            if(q5){
                set_union(four[0].begin(), four[0].end(), four[1].begin(), four[1].end(), inserter(poss,poss.begin()));
            }
            else{
                set_union(four[0].begin(), four[0].end(), four[3].begin(), four[3].end(), inserter(poss,poss.begin()));
            }
        }
    }
    
    if(poss.size()==2){
        if(!ans(*poss.begin())){
            auto it = poss.begin();
            it++;
            ans(*it);
        }
    }
    else{
        ans(*poss.begin());
    }

}

int main()
{
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
  int t=1;
  //cin >> t;
  while(t--){
    solve();
  }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
