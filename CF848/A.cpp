#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int cur = 0;
    int pre;
    int st = -1;
    for(int i = 0; i < n; i++){
        int no;
        cin >> no;
        cur += no;
        if(i != 0){
            if(pre == no && pre == -1) st = 1;
            else if(pre != no){
                st = max(0, st);
            }
        } 
        pre = no;
    }
    cur += st * 4;
    cout << cur << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}