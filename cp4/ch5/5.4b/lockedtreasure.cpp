#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> bin[31];

void init(){
    for(int i = 0; i < 31; i++){
        bin[i].assign(i + 1, 1);
        for(int j = 1; j < i; j++)
            bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
    }
}

void solve(){
    int n,k;
    cin >> n >> k;
    cout << bin[n][k - 1] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--) solve();

}