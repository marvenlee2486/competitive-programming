#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
const int INF = 1e9;
void solve(){
    int id=0;
    int n,m,k;
    cin >> n >> m >> k;
    set<ii> pt;
    vector<int> col[m + 1];
    vector<int> row[n + 1];

    vector<vector<int> > graph(k, vector<int>());
    map<int,int> dep[4];
    vector<ii> ans;
    int sr,sc;
    cin >> sr >> sc;
    col[sc].emplace_back(sr);
    row[sr].emplace_back(sc);
    ans.emplace_back(-1,-1);
    for(int i = 1; i < k; i++){
        int r,c;
        cin >> r >> c;
        pt.insert(ii(r,c));
        col[c].emplace_back(r);
        row[r].emplace_back(c);
    }    
    for(auto& r:row){
        sort(r.begin(),r.end());
    }
    for(auto& c:col){
        sort(c.begin(),c.end());
    }

    // for(auto c:row){
    //     for(auto cc:c) cout << cc << " ";
    //     cout << "\n";
    // }
    
    map<ii,int> mp;
    queue<ii> q;
    q.push(ii(sr,sc));
    mp[ii(sr,sc)] = id++;

    int dr[] = {1,-1,0,0};
    int dc[] = {0,0,1,-1};
    int init[] = {INF,0,INF,0};
    while(!q.empty()){
        int ur,uc;
        tie(ur,uc) = q.front();
        q.pop();
        
        for(int d = 0; d < 4; d++){
            int vr = ur + dr[d];
            int vc = uc + dc[d];

            if(pt.find(ii(vr,vc)) == pt.end()) continue;
            pt.erase(ii(vr,vc));

            mp[ii(vr,vc)] = id++;
            ans.emplace_back(d, d<=1?vc:vr);
            q.push(ii(vr,vc));
            // 0 ,1 move row,
            // 2 ,3, move col
            if(dep[d].find(d<=1?vc:vr) == dep[d].end()) dep[d][d<=1?vc:vr] = init[d];
            
            if(init[d]) dep[d][d<=1?vc:vr] = min(dep[d][d<=1?vc:vr],(d<=1?vr:vc));
            else dep[d][d<=1?vc:vr] = max(dep[d][d<=1?vc:vr],(d<=1?vr:vc));
            graph[mp[ii(ur,uc)]].emplace_back(mp[ii(vr,vc)]);
        }
    }

    for(int d = 0; d < 4; d++){
        for(auto x:dep[d]){
            int r = x.first;
            int c = x.second;
            if(d <= 1) swap(r,c);
            // cout << d << " " << r << " " << c << "\n";
            int idx;
            if(d<=1)
                idx = lower_bound(col[c].begin(),col[c].end(),r) - col[c].begin();
            else
                idx = lower_bound(row[r].begin(),row[r].end(),c) - row[r].begin();
            
            if(d == 0) // ^ so min
                for(int i = idx; i < col[c].size(); i++) graph[mp[ii(col[c][i-1],c)]].emplace_back(mp[ii(col[c][i],c)]); 
            else if (d == 1) // v
                for(int i = idx; i >= 0; i--) graph[mp[ii(col[c][i+1],c)]].emplace_back(mp[ii(col[c][i],c)]); 
            else if (d == 2) // <
                for(int i = idx; i < row[r].size(); i++) graph[mp[ii(r,row[r][i-1])]].emplace_back(mp[ii(r,row[r][i])]);
            else  // >
                for(int i = idx; i >= 0; i--) graph[mp[ii(r,row[r][i+1])]].emplace_back(mp[ii(r,row[r][i])]);
                
        }   
    }


    vector<int> sorting;
    vector<int> deg(k+1);

    for(auto i : graph) for(auto j : i) deg[j]++;
    queue<int> Q;
    for(int i = 0; i < k; i++){
        if(deg[i] ==0) Q.emplace(i);
    }
    while(!Q.empty()){
        auto u = Q.front();
        Q.pop();
        sorting.emplace_back(u);
        for(auto v: graph[u]){
            deg[v]--;
            if(deg[v] == 0) Q.emplace(v);
        }
    }
    if(sorting.size() != k){
        cout << "impossible\n";
        return;
    }

    cout << "possible\n";
    string s = "^v<>";
    for(auto idx:sorting){
        int d,val;
        tie(d,val) = ans[idx];
        if(d == -1) continue;
        cout << s[d] << " " << val << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}