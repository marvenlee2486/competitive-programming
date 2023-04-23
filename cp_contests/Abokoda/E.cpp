#include<bits/stdc++.h>
using namespace std;

int w[15];
int n = 15, m = 65535;

int q(vector<int> input){
    cout << "WEIGH\n";
    cout << "1\n0\n";
    cout << input.size() << "\n";
    for(int c : input) cout << c + 1 << " ";
    cout << endl;
    string s;
    cin >> s;
    if(s == ">") return 1;
    else if(s == "=") return 0;
    else return -1;
}

int solve(){
    vector<int> cur;
    int res = 0;
    int idx = 0;
    int ans = 0;
    do{
        if(res == 1){
            cur.pop_back();
        }
        else if(res == -1){
            cur.back()--;
            ans += w[cur.back()];
            idx = 0;
        }
        if(idx == n){
            return 0;
        }
        cur.emplace_back(idx);
        idx += 1;
        res = q(cur);
    }while(res != 0);
    return ans;
}

int main(){
    cout << "15\n";
    for(int i = 0; i < n; i++){
        w[i] = (1 << (i+1));
        cout << w[i] << " ";
    }
    cout << m << endl;

    int t;
    cin >> t;
    while(t--) solve();

}