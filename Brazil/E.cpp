#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> ii;
vector<multiset<ii>> owner;
vector< vector<int> > graph;
deque<ii> path;
vector<int> age;
vector<int> p;
void dfs1(int u){
    multiset<ii> cur;
    for(auto&[l,r]: owner[u]){
        auto idx = upper_bound(path.begin(),path.end(),ii(r,100000000));

        if(idx==path.begin()){
            cur.insert(ii(l,r));
        }
        else{
            owner[prev(idx)->second].insert(ii(l,r));
        }
    }
    owner[u] = cur;
    
    path.push_front(ii(age[u],u));
    for(int v: graph[u]){
        dfs1(v);
    }
    path.pop_front();
}

multiset<ii> store;
vector<int> ans;
void dfs2(int u){

    for(auto v: owner[u]){
        store.insert(v);
    }
    
    auto it = store.upper_bound(ii(age[u],100000000));
    if(it==store.begin()){
        ans[u] = 0;
    }
    else{
        ans[u] = 
    }
    

    for(int v:graph[u]){
        
        dfs2(v);
    }


    for(auto v: owner[u]){
        auto it = store.find(v);
        store.erase(it);
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    
    graph.assign(n+1,vector<int>());
    age.assign(n+1,0);
    p.assign(n+1,0);
    ans.assign(n+1,0);
    owner.assign(n+1, multiset<ii>());
    for(int i=1;i<n+1;i++){
        cin >> age[i] >> p[i];
        if(i!=1)
        graph[p[i]].push_back(i);
    }

    for(int i=0;i<m;i++){
        int o,l,r;
        cin >> o >> l >> r;
        owner[o].insert(ii(l,r));
    }
    // for(int i =1;i<=n;i++){
    //     for(auto&[l,r]:owner[i]) cout << i << " ";
    // }
    dfs1(1);
    cout << endl;
    // for(int i =1;i<=n;i++){
    //     for(auto&[l,r]:owner[i]) cout << i << " ";
    // }
    dfs2(1);


    

    return 0;
}