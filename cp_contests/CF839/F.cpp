#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

    int n,m,k;
bool order(vector<string> v1, vector<string> v2){
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(v1[i][j] != v2[i][j]){
                if(v1[i][j] != v1[i-1][j]) return true;
                else return false;
            }
        }
    }
    return false;
}

vector<ii> print(vector<string> v1, vector<string> v2){
    vector<ii> res;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(v1[i][j] != v2[i][j]){
                res.emplace_back(i+1,j+1);
            }
        }
    }
    return res;
}

void solve(){
    cin >> n >> m >> k;
    vector<vector<int> > graph;
    vector<pair< vector<string>, int>> copies(k+1);
    for(int i = 0; i < k + 1; i++){
        copies[i].first.assign(n,"");
        copies[i].second = i + 1;
        for(int j = 0; j < n; j++) cin >> copies[i].first[j];
    }
    sort(copies.begin(),copies.end(), [&](auto l, auto r){
        return order(l.first, r.first);
    } );

    cout << copies[0].second << "\n";
    ll q = k;
    vector< vector<ii> > ans;
    for(int i = 1; i < k + 1; i++){
        ans.emplace_back(print(copies[i - 1].first, copies[i].first));
        q += ans.back().size();
        
    }
    cout << q << "\n";
    int idx = 0;
    for(vector<ii> aa: ans){
        for(auto&[x,y]: aa){
            cout << "1 " << x << " " << y << "\n";
        }
        cout << "2 " << copies[idx + 1].second << "\n";
        idx ++;
    }
    


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}

