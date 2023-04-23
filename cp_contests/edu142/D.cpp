#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
// vector<int> ans;
bitset<50000> check[10][10];// i appear at position j;
int n,m;
// idx is affected index, cur is possible;
bitset<50000> possible[10 + 1];

void dfs(bitset<50000> cur, bitset<50000> idx, int depth){
    if(idx.count() == 0 || cur.count() == 0) return;
    // for(int i = 0; i < n; i++){
    //     if(idx[i]) ans[i] = max(ans[i], depth);
    // }
    possible[depth] |= idx;
    if(depth == 10) return;
    // i is number at position depth;
    for(int i = 0; i < 10; i++){
        dfs(cur & check[depth][i] , idx & check[i][depth], depth + 1);
    }
}


void solve(){
    
    // for(int j: ans) cout << j << " ";
    // cout << "\n";
    // for(int i = 0; i < n; i++){
    //     bitset<50000> cur;
    //     cur.set();
    //     int j;
    //     for(j = 0; j < m; j++){
    //         cur &= check[j][a[i][j]];
    //         if(cur.count() == 0) break;
    //     }
    //     cout << j << " ";
    // }
    // cout << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    vector<int> ncol;
     for(int i = 0; i < 10; i++){
        possible[i].reset();
        for(int j = 0; j < 10; j++) check[i][j].reset();
    }
    int iidx = 0;
    while(t--){
        cin >> n >> m;
        ncol.emplace_back(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x;
                cin >> x;
                x--;
                check[x][j].set(iidx);
            }
            iidx++;
        }

    }
    // cout << iidx << "\n";

    
    bitset<50000> cur1,cur2;
    cur1.set(), cur2.set();
    dfs(cur1, cur2, 0);
    iidx = 0;
    for(int n1: ncol){
        for(int i = 0; i < n1; i++){
            int j = 0;
            for(j = 0; j <= 10; j++){
                if(!possible[j][iidx]) break;
            }
            cout << j - 1 << " ";
        }

    cout << "\n";
    }
    
}