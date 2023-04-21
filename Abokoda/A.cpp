#include<bits/stdc++.h>
using namespace std;

int main(){
    string a[] = {"Alice", "Bob", "Cindy"};
    bool can[] = {false, false, false};
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < 3; i++){
        bool gg = false;
        if(s.size() != a[i].size()) continue;
        for(int j = 0; j < s.size(); j++){
            if(s[j] != a[i][j] && s[j] != '.') gg = true;
        }
        if(!gg){
            if(ans != ""){
                cout << "CAN'T TELL\n";
                return 0;
            }
            ans = a[i];
        }
    }
    if(ans == "") cout << "SOMETHING'S WRONG\n";
    else cout << ans <<"\n";
}