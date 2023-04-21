#include<bits/stdc++.h>
using namespace std;
/*
    (-1, -1) (0,-1)
(-1,0) (0,0) (1,0)
    (0,1) (1, -1)
*/
int dx[] = {-1,1,0,-1,0,1};
int dy[] = {0,0,-1,-1,1,1};
using ii = pair<int, int>;
void solve(){
    int n;
    cin >> n;
    // if(n == 1){
    //     cout << "0\n";
    //     return;
    // }
    map<ii,int> mp[n / 2 + 2];
    mp[0][ii(0,0)] = 1;
    for(int i = 1; i <= (n + 1) / 2; i++){
        for(auto&[p,v]: mp[i - 1]){
            auto&[x,y] = p;
            for(int d = 0; d < 6; d++){
                mp[i][ii(x + dx[d], y + dy[d])] += v;
            }
        }
    }
    int ans = 0;
    for(auto&[p,v]: mp[n / 2]){
        auto&[x,y] = p;
        for(int d = 0; d < 6; d++){
            if(mp[n - n/2 - 1].find(ii(x + dx[d], y + dy[d])) == mp[n - n/2 - 1].end()) continue;
            // cout << v << "\n";
            ans += v * mp[n - n/2 - 1][ii(x + dx[d], y + dy[d])];
        }
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}