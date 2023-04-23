#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    int cur = 1, merge = 0, zero = 0;
    bool gg = false;
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        if(c == 1) cur++;
        if(c == -1) merge++;
        if(c == 0) zero++, merge++;

        if(cur - 1 < merge){
            merge--;
            cur++;
            zero--;
        }
        if(zero < 0) gg = true;
    }
    if(gg){
        cout << "-1\n";
        return;
    }
    int div = cur - merge;
    int g = __gcd( (unsigned int)cur, (unsigned int)div);
    div/=g;
    cur/=g;
    cout << cur << " " << div << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}