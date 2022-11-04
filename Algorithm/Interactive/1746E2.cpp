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
#define CKMAX(a,b) a=max(a,b)
#define CKMIN(a,b) a=min(a,b)
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

bool q(vector<int> A){
    cout << "? " << A.size();
    for(int c:A) cout << " " << c;
    cout << endl;
    string s ;
     cin >> s;
    return s=="YES";

}

bool qa(int x){
    cout << "! " << x << endl;
    string s;
    cin >> s;
    return s == ":)";
}

// O( N^2 M^2 ) ， N = M de hua, N = 50 is possible .
const int N = 50;
int dp[N][N]; // minimum number with A is ask in last question as yes, B is not ask but correct
ii choice[N][N]; // the choice or a and b is optimal

int topdown(int i, int j){
    int sum = i + j;
    if(sum <=2){
        return dp[i][j];
    }
    if(choice[i][j] != ii(-1,-1)){
        return dp[i][j];
    }
    
    for(int a = 0; a<=i; a++ ){
        for(int b =0; b <= j; b++){
            if(a==0 && b==0) continue;
            int q = max(topdown(a+b,i-a), topdown(i-a + j-b, a) );
            if(q+1 < dp[i][j]){
                dp[i][j] = q+1;
                choice[i][j] = ii(a,b);
            }
        }
    }
    return dp[i][j];

}

void init(){
    
    // Initialize 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i+j<= 2){
                dp[i][j] = 0;
            }
            else dp[i][j] = N+1;
            choice[i][j] = ii(-1,-1);
        }
    }
    
    for(int sum = N; sum>0; sum--){
        for(int j = N-1; j>=0; j--){
            topdown(sum-j,j);
        }
    }

    // for(int sum = 3; sum < N; sum ++){
    //     for(int i = 0; i <= sum; i++){
    //         int j = sum - i;
    //         // starting i and j
        
    //         for(int i2 = 0 ; i2 < j; i2++){
    //             for(int j2 = 0 ; j2 < N; j2++){
    //                 if(i2+i >=N || j2+j >=N) continue;
                    
    //                 if(  dp[i][j] + 1 < dp[i2+i][j2+j] ){
    //                     dp[i2+i][j2+j] = dp[i][j] +1;
    //                     choice[i][j] = ii(i2,j2);
    //                 }

    //             }
    //         }
    //     }
    // }

}

void recur(vector<int> A, vector<int> B){

    if(A.size() + B.size() <=2){
        for(int c: A) {
            if(qa(c)) return;
        }
        for(int c: B) {
            if(qa(c)) return;
        }
        return;
    }

    ii selection;
    if(A.size() + B.size() < N){
        selection = choice[A.size()][B.size()];
    }
    else{
        selection = ii(A.size()/2, B.size()/2);
    }
    // cerr << A.size() << ": ";
    // for(int c:A)  cerr << c << " ";
    // cerr << "\n";
    
    // cerr << B.size() << ": ";
    // for(int c:B)  cerr << c << " ";
    // cerr << "\n";
    // cerr << selection.first << " " << selection.second << "\n";
    vector<int> C, Ap,Bp,a;

    // A U B and A N B = 0,
    // C = a U b , where a subset of A and b subset of B
    // A' = A - a, aB' = a + B - b
    assert(selection != ii (-1,-1));
    for(int i = 0; i < A.size(); i++){
        if(i < selection.first) {
            C.push_back(A[i]);
            a.push_back(A[i]); // For pass purpose; below
        }
        else Ap.push_back(A[i]);
    }

    for(int i = 0; i < B.size(); i++){
        if(i < selection.second) C.push_back(B[i]);
        else Bp.push_back(B[i]);
    }
    
    

    // if A is true, C = YES (true)   ->  a is answer
    // if A is true, C = YES (false)  ->  A-a is answer
    // if A is true, C = NO (true)    ->  A-a is answer
    // if A is true, C = NO (false)    -> a is answer

    // if A is false, C = YES (true) -> b is answer
    // if A is false, C = NO (true)  -> B-b is answer
    
    // CONCLUSION
    // when C = YES ( B-b is wrong) -> Total valid is a + A' + b -> pass (a+b, A') 
    // when C = NO  ( b is wrong) -> Total valid is a + A' + B' -> pass  (A'+B', a)
    
    if(q(C)){
        recur(C,Ap); // a+b , A-a
    }
    else{
        for(int c: Ap) Bp.push_back(c);
        recur(Bp,a); // A-a + B-b, a
    }

}


void solve(){
    int n;
    cin >> n;
    vector<int> B;
    for(int i = 0; i < n; i++) B.push_back(i+1);

    recur(B,{});
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
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
