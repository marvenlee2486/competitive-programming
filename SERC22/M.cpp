// MouseTrap
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<__int128_t, __int128_t>;
const ll INF = 1e9;
const ld EPS = 1e-9;
void solve(){
    ll n,xx;
    cin >> n >> xx;
    vector<ll> c(n, 0);
    vector< vector<ll> > graph(n, vector<ll>());
    for(auto&i: c) cin  >> i;
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    // get the path and a b pair
    vector<ii> path;
    vector<int> add;
    vector<int> ans(n, 0);
    function<bool(int,int)> dfs =[&](int u, int anc = - 1){
        if(u == n - 1) return true;
        bool is = false;
        ll a = 0,b = 0;
        for(int v: graph[u]){
            if(v == anc) continue;
            if(dfs(v,u)){
                is = true;
                add.emplace_back(v);
                a = c[v];
            }
            
            b += c[v];
        }
        if(is) path.emplace_back(a,b);
        return is;
    };

    dfs(0, -1);

    // Check if path correct
    // for(auto&[a,b]:path) cout << a << " " << b << "\n";

    ld l = 0, r = 0;
    for(auto&[a,b]:path){
        r = max(r, ld(1.0/a - 1.0/b));
    }
    // cout << l << " " << r << "\n";
    
    while(fabs(r - l) > EPS){
        ld m = (r + l) / 2;
        // cout << " m = " << m << '\n';
        ld need = 0;
        // 
        // 1/(a+x) - 1/(b+x) = m
        // (b - a)/(ab + (a+b)x + x^2) = m
        // x^2 + (a+b)x + ab - (b - a)/m  = 0;
    
        for(auto&[a,b]: path){
            ld c = (a + b) * (a + b) - 4 * a * b;
            // cout << c << " ";
            c += 4 * (b - a)/m;
            // cout << c << " ";
            c = sqrt(c);
            // cout << c << " ";
            ld x = -(a + b) + c;
            
            x /= 2;
            // cout << x << "\n";
            if(x < 0) x = 0;
            need += x;
        }
        if(need > xx) l = m;
        else r = m;
    }
    // for(auto& x: temp) cout << x << " ";
    ll cur = 0;
    // pq method
    priority_queue<pair<ld,ll>> pq;
    for(int i = 0; i < path.size(); i++){
        /*
        
        (a + 1)/(b + 1) / (a/b)

        b/a * (a+1)/(b+1)
        */
        __int128_t a,b;
        tie(a,b) = path[i];
            
        ld xte = -(a + b) + sqrt( (a + b) * (a + b) - 4 * (a * b - (b - a)/r)); 
        xte /= 2;
            
        if(xte < 0) xte = 0;
        ll x = xte ;
        ans[add[i]] = x;
        path[i].first += x;
        path[i].second += x;
        cur += x;
        a += x, b += x;
        pq.emplace( (1.0 * b / a ) * (1.0 * (a + 1)/(b + 1)), i);
    }
    assert(cur <= xx);
    while(cur < xx){
        auto[_,i] = pq.top();
        pq.pop();
    
        ans[add[i]] += 1;
        path[i].first += 1;
        path[i].second += 1;
        ld a, b;
        tie(a,b) = path[i];
        pq.emplace( (1.0 * b / a ) * (1.0 * (a + 1)/(b + 1)), i);
        cur++;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}