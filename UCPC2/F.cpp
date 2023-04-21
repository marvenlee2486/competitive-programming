#include<bits/stdc++.h>
using namespace std;

string add(string s1, string s2){
    if(s1.size() > s2.size()) swap(s1,s2);

    int c = 0;
    string ret = "";
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while(i >= 0 && j >= 0){
        int val = s1[i] + s2[j] - 2 * '0' + c;
        ret += '0' + val % 10;
        c = val / 10;
        i--;
        j--;
    }
    while(j >= 0){
        int val = s2[j] - '0' + c;
        ret += '0' + val % 10;
        c = val/10;
        j--;
    }
    while(c != 0){
        ret += '0' + c;
        c /= 10;
    }

    reverse(ret.begin(),ret.end());
    return ret;
}

int sign(string s1, string s2){
    if(s1.size() < s2.size()) return -1;
    else if(s1.size() > s2.size()) return 1;

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] < s2[i]) return -1;
        if(s1[i] > s2[i]) return 1;
    }
    return 0;
}

// void min(string& s1, string s2){
//     if(s1.size() < s2.size()) return;
//     else if(s1.size() > s2.size()) {
//         s1 = s2;
//         return;
//     }

//     for(int i = 0; i < s1.size(); i++){
//         if(s1[i] < s2[i]) return;
//         if(s1[i] > s2[i]) {
//             s1 = s2;
//             return;
//         }
//     }
// }

void solve(){
    int n, k;
    cin >> n >> k;  
    string s;
    cin >> s;
    int len = n / (k + 1);
    string ans = "NO";
    function<void(int, string, int pre)> dfs = [&](int i, string poss, int pre) {
        if(ans != "NO" && sign(ans,poss) <= 0) return;
        
        if(i == k){

            poss = add(poss, s.substr(pre, n - pre));
            if(ans == "NO") ans = poss;
            else if( sign(ans, poss) > 0) ans = poss;
            return;
        }
        
        int dx[] = {0, 1, -1, 2};
        for(int d:dx){
            if(pre + len + d <= 0 || len + d <= 0 || pre + len + d >= n) continue;
            if(n - ((k - i) * (len + 2)) > pre + len + d || n - ((k - i) * (len - 1)) < pre + len + d ) continue;
                
            if(i == 0) dfs(i + 1, s.substr(0, len + d), len + d);
            else dfs(i + 1, add(s.substr(pre, len + d), poss), pre + len + d);
        }
    };
    dfs(0, "0", 0);
    assert(ans != "NO");
    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}