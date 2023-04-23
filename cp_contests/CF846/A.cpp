#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin >> n;
    vector<int> odd;
    vector<int> even;
    
    for(int i = 0; i < n; i++) {
        cin >> x;
        x %= 2;
        if(x == 1) odd.emplace_back(i + 1);
        else even.emplace_back(i + 1);

    }

    if(odd.size() == 0 || (odd.size() < 3 && even.size() < 2)){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if(odd.size() >= 3){
        cout << odd[0] << " " << odd[1] << " " << odd[2] << "\n"; 
    }
    else{
        cout << odd[0] << " " << even[0] << " " << even[1] << "\n";
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}