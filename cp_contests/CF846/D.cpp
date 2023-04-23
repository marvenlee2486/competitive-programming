#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n = 0;
    int cnt = 0;
    cin >> cnt;
    int idx = 0;
    while(cnt != 0){
        cout << "- " << (1 << idx) << endl;
        int ncnt = 0;
        cin >> ncnt;
        while(ncnt >= cnt){
            cout << "- " << (1 << idx) << endl;
            idx++;
            cin >> ncnt;
        }
        n += (1<<idx);
        idx++;
        cnt = ncnt;
    }
    cout << "! " << n << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}