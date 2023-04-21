#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
/*
3
4 5 3 
ULDDRR 
4 5 0 
UUUUUUU 
4 5 10 
UUUUUUU
*/ 

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int vertical = 0, horizontal = 0;
    int hmax = 0, hmin = 0, vmax = 0, vmin = 0;
    for(char c: s){
        if(c == 'U') vertical++;
        else if(c == 'D') vertical--;
        else if(c == 'L') horizontal++;
        else if(c == 'R') horizontal--;
        
        vmax = max(vmax, vertical);
        vmin = min(vmin, vertical);
        hmax = max(hmax, horizontal);
        hmin = min(hmin, horizontal);
    }
    int c1 = hmax, r1 = vmax, c2 = m - 1 + hmin, r2 = n - 1 + vmin;
    //cout << vmax << " " << vmin << " " << hmax << " " << hmin << "\n";

    //cout << r1 << " " << c1 << " " << r2 << " " << c2 << "\n";
    if(r2 < r1 || c2 < c1){
        if(k == 0) cout << n * m << "\n";
        else cout << "0\n";
        return;
    }
    int rd = r2 - r1 + 1;
    int cd = c2 - c1 + 1;
    // cout << rd << " " << cd << "\n";
    if(rd * cd < k) {
        cout << "0\n";
        return;
    }

    set<ii> position;
    vector<vector<int> > a(n + 2, vector<int>(m + 2, 0));
    int cr = r1, cc = c1;
    position.emplace(cr,cc);
    a[cr][cc]++;
    a[cr + rd][cc]--;
    a[cr][cc + cd]--;
    a[cr + rd][cc + cd]++;
    for(char c: s){
        if(c == 'U') cr--;
        else if(c == 'D') cr++;
        else if(c == 'L') cc--;
        else if(c == 'R') cc++;

        if(position.find(ii(cr,cc)) != position.end()) continue;
        position.emplace(cr,cc);
        a[cr][cc]++;
        a[cr + rd][cc]--;
        a[cr][cc + cd]--;
        a[cr + rd][cc + cd]++;
    }

    int target = rd * cd - k;
    vector<vector<int> > p(n + 2, vector<int>(m + 2, 0));
    int ans = 0;
    // cout << target << " ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) p[i][j] = a[i][j];
            else if(i == 0) p[i][j] = p[i][j - 1] + a[i][j];
            else if(j == 0) p[i][j] = p[i - 1][j] + a[i][j];
            else p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
            if(p[i][j] == target) ans++;
        }
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}