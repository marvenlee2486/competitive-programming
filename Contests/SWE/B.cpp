#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    ii pos[n*n];
    int col[n];
    int row[n];
    ll ans = 0;
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int s;
            cin >> s;
            s--;
            pos[s] = ii(i,j);
        }
    }

    for(int idx = 0; idx < n*n; idx++){
        int i,j;
        tie(i,j) = pos[idx];
        
        ans += row[i] * (n - col[j] - 1) + col[j] * (n - row[i] - 1); 

        row[i]++,col[j]++;
    }
    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}