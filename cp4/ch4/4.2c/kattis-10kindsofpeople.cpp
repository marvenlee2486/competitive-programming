

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
int arr[1002][1002];
vs grid;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void floodfill(int x, int y, int loc, char b){
    if(x<0 || x>=r || y<0 || y>=c) return;
    if(grid[x][y]!=b) return;
    arr[x][y]=loc;
    grid[x][y]=b+2;
    rep(i,0,4){
        floodfill(x+dx[i], y+dy[i],loc, b);
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
    FILL(arr,-1);
    int loc = 0;
    rep(i,0,r){
        rep(j,0,c){
            if( arr[i][j] != -1 ) continue;
            floodfill(i,j,loc,grid[i][j]);
            loc++;
        }
    }

    int n; cin >> n;
    while(n--){
        int x1,y1,x2,y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        x1--,y1--,x2--,y2--;
        if(arr[x1][y1]==arr[x2][y2] ){
            cout << ( (grid[x1][y1]=='2')?"binary\n":"decimal\n" );
        }
        else cout <<"neither\n";

    }
    

}
  
