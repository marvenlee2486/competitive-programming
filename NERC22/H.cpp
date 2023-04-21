#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    if(n==1){
        cout << "YES\n0\n";
        return 0; 
    }
    if(n==k){
        cout << "NO\n";
        return 0;
    }
    if(n==2){
        cout << "YES\n1\n1 2\n";
        return 0;
    }
    if(k==1){
        cout << "YES\n";
        cout << n << "\n";
        for(int i = 2; i <= n; i++){
            cout << i - 1 << " " << i << "\n";
        }
        cout << 1 << " " << n << "\n";
        cout << "\n";
        return 0;
    }
    cout << "YES\n";
    vector<pair<int,int>> ans;
    for(int i = 2; i <= n; i++) ans.emplace_back(1,i); 

    int curk = 2;
    int cur = 2;
    int len = 1;
    while(curk != k){
        if( cur <= n/2 ){
            for(int i = 0; i < len; i++)
                ans.emplace_back( cur ,n - i);
            len++;
            cur++;
        } 
        else{
            for(int i = cur + 1; i <= n; i++) 
                ans.emplace_back( cur , i);
            cur--;
        }
        if(len == n/2 ) {
            cur = n - 1;
            len = 0;
        }

        curk++;
    }
    cout << ans.size() << "\n";
    for(auto&[l,r]: ans){
        cout << l << " " << r << "\n";
    }
}