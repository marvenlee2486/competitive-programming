/*
4
8
12
16
20
24
28 
*/

// all odd + only one(0,4,8)
// 2 + 6 only
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int, int>> a1, a2;
    vector<string> store;
    bool got[n];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        store.emplace_back(s);
        int cnt = 0;
        string s1 = "", s2 = "";
        got[i] = false;
        for(char c: s) {
            if( c == '2' || c == '6') s2 += c;
            else if( (c - '0') % 2 == 1) s1 += c;
            else got[i] = true;
        }
        a1.emplace_back(s1.size(), i);
        a2.emplace_back(s2.size(), i);
    }
    
    sort(a1.begin(), a1.end(), [](auto l,auto r){
        return l.first > r.first;
    });

    sort(a2.begin(), a2.end(), [](auto l,auto r){
        return l.first > r.first;
    });

    int ans1 = 0, ans2 = 0;
    vector<int> idx1, idx2;
    for(int i = 0; i < k; i++){
        ans1 += a1[i].first;
        idx1.emplace_back(a1[i].second); 

        ans2 += a2[i].first;
        idx2.emplace_back(a2[i].second);
    }
    // for(int i = 0; i < n; i++) cout << a1[i].first << " ";
    // cout << "\n";
    string ans = "";
    if(ans1 >= ans2){
        if(ans1 == 0){
            for(int idx: idx1) cout << idx + 1 << " ";
            cout << "\nempty\n";
            return 0;
        }
        bool gg = true;
        for(int i = 0; i < k; i++){
            if(got[a1[i].second]) gg = false;
        }
        int idx = k;
        while(gg && idx != n && a1[idx].first == a1[idx - 1].first){
            
            if(got[a1[idx].second]){
                gg = false;
                idx1.pop_back();
                idx1.emplace_back(a1[idx].second);
                break;
            }
            idx++;
        }
        gg = false;
        for(int idx: idx1){
            cout << idx + 1 << " ";
            for(char c : store[idx]){
                if( (c - '0') % 2 == 1) ans += c;
                else if(!gg && (c == '0' || c == '4' || c =='8')){
                    ans += c;
                    gg = true;
                }
            }
        }
    }
    else{
        for(int idx: idx2){
            cout << idx + 1 << " ";
            for(char c : store[idx]){
                if(c =='2' || c == '6') ans += c;
            }
        }
    }
    cout << "\n" <<  ans << "\n";
}