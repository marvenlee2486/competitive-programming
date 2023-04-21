#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
struct trie{
    trie* next[10];
    trie(){
        memset(next, 0, sizeof next);
    }
};
int n,m;
void insert(trie* root, vector<int> a){
    vector<int> aa(m, 0);
    for(int i = 0; i < a.size(); i++){
        aa[a[i]] = i;
    }
    for(int i = 0; i < a.size(); i++){
        if(root->next[aa[i]] == NULL) root->next[aa[i]] = new trie();
        root = root->next[aa[i]];
    }
}

int query(trie* root, vector<int> a){
    for(int i = 0; i < m; i++){
        if(root->next[a[i]] == NULL) return i;
        root = root->next[a[i]];
    }   
    return m;
}


void solve(){
    cin >> n >> m;
    trie* root = new trie();
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
        insert(root, a[i]);
    }
    
    for(int i = 0; i < n; i++) cout << query(root,a[i]) << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}