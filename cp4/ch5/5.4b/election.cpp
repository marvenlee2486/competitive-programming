#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> bin[51];

void init(){
    bin[0].assign(1,1);
    for(int i = 1; i < 51; i++){
        bin[i].assign(i + 1, 1);
        for(int j = 1; j < i; j++){
            bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
        }
    }
}

void solve(){
    ll n,w,v1,v2;
    cin >> n >> v1 >> v2 >> w;
    ll l = n - v1 - v2;
    // need at least how many.
    ll need = 0, total = 0;
    for(int i = 0; i <= l; i++){
        if(v1 + i > v2 + (l - i)){
            need += bin[l][i];
        }
        total += bin[l][i];
    }
    if(need == 0) cout << "RECOUNT!\n";
    else{
        long double per = need * 100.0 / total;
        if(per > w){
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
        }
        else cout << "PATIENCE, EVERYONE!\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    init();
    while(t--) solve();
}