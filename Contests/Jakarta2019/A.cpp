#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int p[n];
    int minp = 0, maxp= 0;
    for(int i = 0; i < n ; i ++) {
        cin >> p[i];
        if(p[i]==1) minp = i;
        else if(p[i] == n) maxp=i;
    }
    swap(p[minp],p[maxp]);
    for(int i = 0 ; i < n; i++) cout << p[i] << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;//cin >> t;
    while(t--)
    solve();
}