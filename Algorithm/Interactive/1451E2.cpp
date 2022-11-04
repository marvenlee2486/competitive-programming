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

    int And(int i, int j){
        cout << "AND " <<  i+1 <<  " " << j+1 << endl;
        int x;
        cin >> x;
        assert(x!=-1);
        return x;
    }

    int Or(int i, int j){
        cout << "OR " <<  i+1 <<  " " << j+1 << endl;
        int x;
        cin >> x;
        assert(x!=-1);
        return x;
    }

    int Xor(int i,int j){
        cout << "XOR " <<  i+1 <<  " " << j+1 << endl;
        int x;
        cin >> x;
        assert(x!=-1);
        return x;
    }

    void solve(){
        int n;
        cin >> n;

        int a[n];
        memset(a,0,sizeof a);
        int same[n];
        int result[2];
        int temp1 = -1,temp2;
        bool first = false;
        map<int,int> st;
        for(int i = 1; i < n ; i ++){
            same[i] = Xor(0,i);
            if(temp1 != -1) continue;
            if(st.find(same[i])!=st.end()){
                first = true;
                temp1 = i;
                temp2 = st[same[i]];
                continue;
            }
            st[same[i]] = i;
            if(i!=1) {
                if(same[i]== n-1-same[1]) {
                    temp2 = i;
                    temp1 = 1;
                    continue;
                }    
            }
            if(i>=3){
                if(same[i] == n-1-same[2]){
                    temp2 = i;
                    temp1 = 2;
                    continue;
                }
            }
        }

        if(st.find(0)!=st.end()){
            result[0] = And(0,st[0]);
            a[0] = result[0];        
        }
        else if(!first){
            assert(temp1!=-1);
            
            result[0] = And(0,temp1);
            result[1] = And(0,temp2);
            for(int i = 0; i<(int)log2(n);i++){
                // 0 and temp1 different
                if( (1<<i) & same[temp1]){
                    a[0] += ((1<<i) & result[1]);
                }
                // 0 and 1 same
                else{
                    a[0] += ((1<<i) & result[0]);
                }
            }
        }
        else{
            assert(temp1!=-1);
            result[0] = And(temp1,temp2);
            a[0] = result[0] ^ same[temp1];
        }
        
        for(int i =1;i<n;i++){
            a[i] = same[i]^a[0];
        }
        cout << "! ";
        for(int i = 0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;



    }

    int main()
    {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
