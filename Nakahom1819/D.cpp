#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int minv=0;
    int ans = 0;
    if(n==0){
        cout << "0\n";
        return;
    }
    cin >> minv;
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        if(x-minv >20) {
            minv = x;
            ans++;
        }
    }
    ans++;
    cout << ans <<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
}