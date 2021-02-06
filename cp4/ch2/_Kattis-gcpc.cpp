#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;
typedef long double ld;

//typelower_bounddef priority_queue<long long> pq;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;


#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
// if else int i = (number <0) ? 1:0 -  if (number <0) i=1 else 0
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


struct CompareID{
    constexpr bool operator()(iii const& lhs, iii const& rhs) const
    {
        if(lhs.se.fi>rhs.se.fi) return true;
        elif (lhs.se.fi<rhs.se.fi) return false;

        if(lhs.se.se<rhs.se.se) return true;
        elif (lhs.se.se>rhs.se.se) return false;

        if(lhs.fi<rhs.fi) return true;
        else return false;
        // return (lhs.fi > rhs.first || (lhs.first==rhs.first && lhs.second.first<rhs.second.first )|| (lhs.first==rhs.first && lhs.second.first == rhs.second.first && lhs.second.second < rhs.second.second));
    }
};

typedef tree<iii, null_type, CompareID, rb_tree_tag,tree_order_statistics_node_update> ost;


int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 //freopen("OUT.txt","w",stdout);

 ost tree;
 int n,m;
 cin >> n >> m;
 rep(i,0,n) tree.insert( iii(i+1,ii(0,0)));
 ii score[n+1];
 rep(i,0,n) score[i]=ii(0,0);
 rep(i,0,m){
    ll t,p;
    cin >> t >> p;
    tree.erase(tree.find( iii(t,score[t])));
    score[t].fi+=1;
    score[t].se+=p;
    tree.insert(iii(t,score[t]));
   // cout << tree.order_of_key(ii(score[1]));

    //rep(i,0,n) cout <<  tree.find_by_order(i)->se << " ";
    cout << tree.order_of_key(iii(1,score[1])) +1 << endl;
 }
}
