#include<bits/stdc++.h>
using namespace std;

bool is(vector<int> a){
    for(int i = 2; i < a.size(); i++){
        if(a[i] - a[i-1] != a[i-1] - a[i-2]) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(auto &i:a) cin >> i;
    if(is(a)) cout << "arithmetic\n";
    else{
        sort(a.begin(),a.end());
        if(is(a)) cout << "permuted arithmetic\n";
        else cout << "non-arithmetic\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}