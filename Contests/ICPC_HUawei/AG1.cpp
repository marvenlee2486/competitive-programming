#include <bits/stdc++.h>
using namespace std;
using vvl = vector<vector<int> >;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int dummy;
        cin >> dummy >> dummy >> dummy;
    }
    int ans = sqrt(n);
    int left = n - ans*ans;
    int size[ans+1];
    for(int i =0 ; i<ans; i++) size[i] = ans;
    int idx = 0;
    while(left>0){
        if(idx>=ans) break;
        size[idx]++;
        left--;
        idx++;
    }
    size[ans]=left;
    if(size[ans]!=0) cout << ans+1 << "\n";
    else cout << ans << "\n";
    idx= 0;
    for(int i=0;i<=ans;i++){
        if(size[i]==0) break;
        cout << size[i] << " ";
        for(int j=0;j<size[i];j++) cout << idx++ << " ";
        cout << "\n";
    }
    return 0;
}