#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
class dsu{
    public:
    vi p,sz;
    int n;
    int total = 0;
    vector<set<int>> anti;
    vector<set<int>> test;
    int findparent(int u){
        return (p[u] == u)?u:p[u] = findparent(p[u]);
    }

    void unionset(int u, int v){
        u = findparent(u), v = findparent(v);
        if(u == v) return;
        // v as head;
        p[u] = v;
        sz[v] += sz[u];
        sz[u] = 0;
        for(auto x: anti[u]) anti[v].insert(x);
        anti[u].clear();
    }

    void testing(){
        for(int i = 0; i < n; i++){

        }
    }

    dsu(int n):n(n){
        p.assign(n,0);
        sz.assign(n,1);
        anti.assign(n,set<int>());
        for(int i = 0; i < n; i++) p[i] = i;
    }
};

void solve(){
    int n;
    cin >> n;

    dsu d(n);

    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}