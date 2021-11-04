

#include <bits/stdc++.h>
using namespace std;
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
int r,c;
vs grid;
int ans =0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void floodfill(int x, int y){
    if(x<0 || x>=r || y<0 || y>=c) return;
    if(grid[x][y]=='1') {
        ans++;
        return;
    }
    elif(grid[x][y]=='2') return;

    grid[x][y]='2';
    rep(i,0,4){
        floodfill(x+dx[i], y+dy[i]);
    }    

}

int main()
{ 
 //ios_base::sync_with_stdio(0);
 //cin.tie(0);
 //cout.tie(0);
 //freopen("UT.txt","w",stdout);
    cin >> r >> c;
    rep(i,0,r){
        str s; cin >> s;
        grid.pb(s);
    }
    

    rep(i,0,r){
        if(grid[i][0] == '1' ) ans ++;
        else floodfill(i,0);

        if(grid[i][c-1] == '1' ) ans ++;
        else floodfill(i,c-1);
    }
    
    rep(i,0,c){
        if(grid[0][i] == '1' ) ans ++;
        else floodfill(0,i);

        if(grid[r-1][i] == '1' ) ans ++;
        else floodfill(r-1,i);
    }

    cout << ans <<"\n";
    
    

}
  
