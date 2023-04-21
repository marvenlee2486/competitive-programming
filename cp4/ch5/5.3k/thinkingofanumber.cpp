#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    while(cin >> n && n){
        int low = 0, high = INF; 
        vector<int> a;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            string dummy; cin >> dummy;
            int val; cin >> val;

            if(s == "less"){
                high = min(val, high);
            }
            else if(s == "greater"){
                low = max(val, low);
            }
            else{
                a.emplace_back(val);
            }
        }
        if(high == INF){
            cout << "infinite\n";
            continue;
        }
        bool gg = true;
        for(int i = low + 1; i < high; i++){
            bool ok = true;
            for(int p:a){
                if(i % p != 0){
                    ok = false;
                    break;
                }
            }
            if(ok) {
                gg = false;
                cout << i << " ";
            }
        }
        if(gg) cout << "none";
        cout << "\n";
    }
}