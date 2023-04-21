#include<bits/stdc++.h>
using namespace std;

struct dsu{
    int n;
    vector<int> p;
    dsu(int n):n(n){
     p.assign(n,-1);
    }

    int findp(int u){
        if(p[u] == -1 || u == -1 || u  >= n) return -1;
        return (p[u] == u)? u: p[u] = findp(p[u]);
    }

    void unionset(int u, int v){
        u = findp(u), v = findp(v);
        if(u == -1 || v == -1) return;
        p[u] = v;
    }

    void set(int u){
        p[u] = u;
    }

};

bool solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    map<int, vector<int>> bmp;
    map<int, int> xcnt;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    

    int x; cin >> x;
    for(int i = 0; i < x; i++){
        int cnt; cin >> cnt;
        if(xcnt.find(cnt) == xcnt.end()) xcnt[cnt] = 0;
        xcnt[cnt]++;
    }

    for(int i = 0; i < n; i++){
        // cout << i << " ";
        if(a[i] < b[i]) return false;
        // if(bmp.find(b[i]) == )
        bmp[b[i]].emplace_back(i);
    }
    //cout << "\n";
    dsu* ds = new dsu(n);
    
    for(auto&[u, v]:bmp){
        //if(n == 13) cout << u << " <- u \n";
        int rmb = -2;
        for(int idx: v){
            if(a[idx] == u) {
                ds->set(idx);
                ds->unionset(idx, idx - 1);
                ds->unionset(idx + 1, idx);
            }
            else{
                //if(n == 13) cout << idx << " " << rmb << " ";
                if(rmb == -2 || ds->findp(idx - 1) != ds->findp(rmb)){
                    //if(n == 13) cout << "HERE";
                    
                    rmb = idx;
                    if(xcnt.find(u) == xcnt.end() || xcnt[u] == 0) return false;
                    xcnt[u]--;
                }
                //if(n == 13)  cout << "\n";
                ds->set(idx);
                ds->unionset(idx, idx - 1);
                ds->unionset(idx + 1, idx);
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) cout << (solve()?"YES\n":"NO\n");
}