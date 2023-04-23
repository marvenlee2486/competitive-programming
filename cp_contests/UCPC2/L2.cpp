#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))                    // the key operation

using vll = vector<int>;
using vi = vector<int>;
using ll = long long; 

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> number(n, 1);
    multiset<int> use;
    
    for(auto&i : a) cin >> i;
    for(auto&i : b) cin >> i;
    for(int i = 0; i < k; i++){
        int xx;
        cin >> xx;
        use.emplace(xx);
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        if(j < m && a[i] == b[j]) j++;
    }
    if(j != m){
        cout << "NO\n";
        return;
    }
    set<int> pos;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}

/*
1
5 2
*/