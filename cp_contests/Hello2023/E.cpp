#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
int n;
int q(int idx){
    cout << "? " << idx + 1 << " ";
    for(int i = 0; i < n; i++){
        if(i != idx) cout << '1'; 
        else cout << '0';
    }
    cout << endl;
    int ans = 0;
    cin >> ans;
    return ans;
}

int q(int idx, string s){
    cout << "? " << idx + 1 << " " << s << endl;
    int ans; cin >> ans;
    return ans;
}


void solve(){
    cin >> n;
    vector<ii> a;
    for(int i = 0; i < n; i++){
        a.emplace_back(q(i), i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    string ans = "";
    int rmb = 1;
    for(int i = 0; i < n; i++) ans += '0';
    ans[a[0].second] = '1';
    for(int i = 1; i < n; i++){
        if( q(a[i].second, ans) == 0){
            if(rmb == -1) rmb = i;
        }
        else{
            if(rmb == -1){
                ans[a[i].second] = '1';
            }
            else {
                for(int j = rmb; j <= i; j++){
                    ans[a[j].second] = '1';
                }
            }

            rmb = -1;
        }
    }
    cout << "! " << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
}