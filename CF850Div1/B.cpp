#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    unordered_map<char,int> mp;
    mp['w'] = 0;
    mp['n'] = 2;
    mp['i'] = 1;
    vector<int> list[3][3];
    // unordered_map<char, vector<int> > mp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int flag[] = {0,0,0};
        vector<int> extra;
        for(char c: s){
            int idx = mp[c];
            if(flag[idx]){
                extra.emplace_back(idx);
            }
            flag[idx] = 1;
        }
        for(int j = 0; j < 3; j++){
            if(flag[j] == 0){
                cout << extra.back() <<  " " << j << "\n";
                list[j][extra.back()].emplace_back(i);
                extra.pop_back();
                ans++;
            }
        }
    }
    string s = "win";
    vector<tuple<int, char, int, char> > aans;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < i; j++){
            while(list[i][j].size() != 0){
                int curi = i, curj = j;
                while(list[curi][curj].size() != 0){

                    curi = curj 
                }
            }
            // for(int k = 0; k < list[i][j].size(); k++) 
            // cout << list[i][j][k] << " " << s[j] <<  " " << list[j][i][k] << " " << s[i] << "\n";
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}