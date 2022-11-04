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

const ll MOD = 998244353;
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

map<int, int> mpp;
vector< vector<int> > arr;
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    arr.assign(n,vector<int>(2,0));
    for(int i =0 ;i<n;i++){
        int x,y;
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
        mpp[x] = i;
        mpp[y] = i;
    }

    int curmin[2] = {1,1}; // o is front, 1 is back
    int curmax[2] = {2*n, 2*n}; 
    int idx;
    int taken = 0;
    int turn = 0;
    int place = 0;
    int finalans = 0;
    while(taken != n){
        //cout << taken << "\n";
        while(mpp[curmin[0]]==-1) curmin[0]++;
        while(mpp[curmin[1]]==-1) curmin[1]++;
        if(curmin[0]> curmin[1]) turn = 1;
        else turn = 0;

        //cout << turn << " " << curmin[turn] << " " << curmax[turn] <<"\n";
        if(abs(curmin[0]-curmin[1])<=1  ){
            //cout << "HARRRR\n";
            finalans += min(place - ans, ans);
            ans = 0;
            place = 0;
        }
        idx = mpp[curmin[turn]];
        
        if( arr[idx][turn] != curmin[turn]) {
            ans++;
            swap(arr[idx][0], arr[idx][1]);
        }

        if(arr[idx][1-turn] > curmax[1-turn]){
            cout << "-1\n";
            return;
        }
        curmax[1-turn] = arr[idx][1-turn]-1;
        // mark as taken
        mpp[arr[idx][0]] = -1;
        mpp[arr[idx][1]] = -1;
        taken ++;
        place ++;
        int newmaxv = arr[idx][1];


        for(int i = curmax[turn]; i >= newmaxv; i--){
            idx = mpp[i];
            if(idx == -1) continue;
            //cout << arr[idx][0] << " " <<  arr[idx][1] <<"\n";
            if( arr[idx][turn] != i) {
                ans++;
                //cout << "SWAPP??\n";
                swap(arr[idx][0], arr[idx][1]);
            }

            // check if decreasing for back.
            //cout << arr[idx][1-turn] << "::"<< curmin[1-turn]<< "\n";
            if(arr[idx][1-turn] < curmin[1-turn] || arr[idx][1-turn] > curmax[1-turn]) {
                cout << "-1\n";
                return;
            }
            curmin[1-turn] = arr[idx][1-turn]+1;
            
            
            // Mark as taken
            mpp[arr[idx][0]] = -1;
            mpp[arr[idx][1]] = -1;
            taken++;
            place++;
        }
        curmax[turn] = newmaxv-1;
        curmin[turn]+=1;
    }
    finalans += min(place - ans, ans);
    ans = 0;
    place = 0;
    cout << finalans << "\n";


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
