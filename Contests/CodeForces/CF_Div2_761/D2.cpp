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

int query(int a,int b, int c){
    cout << "? " << a << " " << b << " " << c << endl;
    int n;
    cin >> n;
    return n;
}
int ans[ N+1];
ii findindex(int one , int zero){
    if(query(3*one +1, 3*one +2, 3*zero+1) ==0 ){
        ans[3*zero+1] = 0;
        ans[3*one +3] = 1;
        ans[3*zero+2] = query(3*one+1,3*one+2,3*zero+2);
        ans[3*zero+3] = query(3*one+1,3*one+2,3*zero+3);

        ans[3*one+1] = query(3*one +1,3*zero+1,3*one+3);
        ans[3*one+2] = 1-ans[3*one+1];
        if(ans[3*one+1]  ==0)
        return ii(3*one+1,3*one+2);
        else 
        return ii(3*one+2,3*one+1);
    }
    if(query(3*zero +1, 3*zero +2, 3*one+1) ==1 ){
        ans[3*zero+3] = 0;
        ans[3*one+1] = 1;
        ans[3*one+2] = query(3*zero+1,3*zero+2,3*one+2);
        ans[3*one+3] = query(3*zero+1,3*zero+2,3*one+3);

        ans[3*zero+1] = query(3*one +1,3*zero+3,3*zero+1);
        ans[3*zero+2] = 1-ans[3*zero+1];

        if(ans[3*zero+1]==0)
        return ii(3*zero+1,3*zero+2);
        else
        return ii(3*zero+2,3*zero+1);
    }

    ans[3*one+2] = 1;
    ans[3*zero+2] = 0;
    
    ans[3*one+3] = query(3*zero+1,3*one+1,3*one+3);
    ans[3*zero+3] = query(3*zero+1,3*one+1,3*zero+3);

    ans[3*zero+1] = query(3*zero+1,3*one+2,3*zero+2);
    ans[3*one+1] = 1-ans[3*zero+1];
    if(ans[3*zero+1]==0)
    return ii(3*zero+1,3*one+1);
    else
    return ii(3*one+1,3*zero+1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        rep(i,0,n+1) ans[i]=-1;
        int st[n/3+1];
        int zero = -1, one= -1;
        rep(i,0,n/3){
            st[i]= query(3*i +1 ,3*i +2 , 3*i +3);
            if(st[i]==1) one = i;
            else zero =i;
        }
        
        auto[x,y] = findindex(one,zero);


        int use;
        rep(i,0,n/3){
            if(i==one||i==zero) continue;
            
            if(st[i]==0)
                use =y;
            else
                use = x;
            if( query(use,3*i+1,3*i+2) == st[i]){
                ans[3*i+1]= st[i];
                ans[3*i+2]= st[i];
                ans[3*i+3]= query(x,y,3*i+3);
            }
            else{
                ans[3*i+3] = st[i];
                ans[3*i+1]= query(x,y,3*i+1);
                ans[3*i+2]= 1- ans[3*i+1];
            } 
        }
        
        int cnt =0;
        rep(i,1,n+1) if(ans[i]==0) cnt++;

        cout <<  "! " << cnt << " ";
        rep(i,1,n+1){
            if(ans[i]==0) cout << i << " ";
        }
        cout << endl;


    }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3) Interactive - Group of X elements, Adjacent Elements


1 2 3  - 0 (at least 2 Crewmates)
1 2  4  - 0 (at least 2 Crewmates)
1 2   5 - 0 (at least 2 Crewmates)
1 2    6 - 1 (at least 2 Imposter)
1 2     7
1 2       8


n/3 + 2  + n -1 




2<(3)<4
3< (4,5)< 6
*/

