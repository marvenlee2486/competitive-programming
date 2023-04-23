#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> ans(2 * n - 1, 0);
    set<int> not_used;
    vector<int> appear(n + 1, 0);
    vector<int> cannot(n + 1, 0);
    cannot[1] = 1;
    bool before = true;
    for(int i = 0; i <= n; i++) not_used.emplace(i);
    for(auto& i: ans){
        cin >> i;
        if(i == 0) before = false;
        if(before){
            appear[i] = 1;
        }
        else{
            if(appear[i] == 1) cannot[i] = 1;
        }
        not_used.erase(i);
    }
    int i = 1;
    not_used.erase(1);
    bool fill = false;
    // cout << not_used.size() << "\n";
    function<void(int,int)> dfs = [&](int u, int anc){
        
        while(i < 2 * n - 1){
            //cout << i << " " <<  u << " " << anc << "\n";
            if(i >= 2 * n - 1) return;

            if(ans[i] != 0){
                if(fill) {
                    i =  2 * n;
                    return;
                }
                if(ans[i] == anc) {
                    i++;
                    return;
                }
                int nxt = ans[i];
                i++;
                dfs(nxt,u);
            }
            else{
                fill = true;
                if(anc == -1 || *not_used.begin() < anc || cannot[u] == 1){
                    int nxt =  *not_used.begin();
                    // cout << nxt << "\n";
                    // cout << "NXT " << " " << nxt << " ";
                    ans[i] = nxt;
                    not_used.erase(not_used.begin());
                    i++;
                    dfs(nxt, u);
                }
                else{
                    ans[i] = anc;
                    i++;
                    return;
                }
            }
        }
        
    };
    ans[0] = 1;
    ans[ 2 * n - 1] = 1;
    dfs(1, -1);
    for(auto&i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}