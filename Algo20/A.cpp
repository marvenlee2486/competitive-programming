#include<bits/stdc++.h>
using namespace std;

int trysee(string s1, string s2, int op[]){
    int p1 = 0, p2 = 0;
    int o = 0;
    while(p1<s1.size() && p2<s2.size()){
    if(p1 < s1.size() && p2<s2.size() && s1[p1] == s2[p2]) p1++,p2++;
    else{
        if(o == 3) return 4;

        if(p2 < s2.size() && p1 < s1.size() && op[o] == 0) p1++,p2++;
        else if(p2 < s2.size() && op[o] == 1) p2++;
        else if(p1 < s1.size() && op[o] == 2) p1++;
        else return 4;
        o++;
    }
    }
    return o;
}

void solve(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int minv = 4;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                int a[] = {i,j,k};
                
                minv = min(minv,trysee(s1,s2,a));
                
            }
        }
    }
    string ans[]{
        "You're logged in!",
"You almost got it. You're wrong in just one spot.",
"You almost got it, but you're wrong in two spots.",
"You're wrong in three spots.",
"What you entered is too different from the real password."
    };
    cout << ans[minv] << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    string s;
    getline(cin,s);
    while(t--) solve();
}