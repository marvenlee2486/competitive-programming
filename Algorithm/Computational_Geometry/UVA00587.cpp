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

struct point{
    double x;
    double y;
    point(double x, double y):x(x),y(y){};
    void translate(point vec){
        x+=vec.x;
        y+=vec.y;
    }
};
  
void solve(string s){
    stringstream ss;
    ss.str(s);
    string token;
    point location(0,0);
    while(getline(ss,token,',')){
        int dist = 0;
        double x = 0, y =0;
        for(char c:token){
            if(c<='9' && c>='0') dist = dist * 10 + c-'0';
            else{
                if(c=='N') y = dist;
                else if(c=='S') y = -dist;
                else if(c=='W') x =  -dist;
                else if(c=='E') x = dist;
            }
        }
        if(x!=0 && y!=0){
            
            x = ((x<0)?-1:1)*sqrt((double)dist*dist/2);
    
            y = ((y<0)?-1:1)*sqrt((double)dist*dist/2);
        }
        location.translate(point(x,y));
    }
    cout << "The treasure is located at (" 
    << fixed << setprecision(3) << location.x << ","
    << fixed << setprecision(3) << location.y << ").\n";

    cout << "The distance to the treasure is " << fixed << setprecision(3) << hypot(location.x,location.y) << ".\n\n";


}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int idx =1;
    while(cin >> s && s!= "END"){
        cout << "Map #" <<idx++ <<'\n';
        solve(s);
    }
    return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/


// 1 2 3 0
//   3 2 1

// 01
// 10
// 11
// 0

// 01
// 00

// 0
