#include<bits/stdc++.h>
using namespace std;          

void solve(int n){
    string a[n];
    string s;
    string token;
    for(int i = 0; i < n; i++){
        getline(cin, s);
        stringstream ss(s);
        vector<string> tokens;
        while(getline(ss,token,' ')){
            tokens.push_back(token);
        }
        char c = tokens[0][0];
        s = "";
        for(int k = 1; k < tokens.size(); k++){
            int val = stol(tokens[k]);
            for(int j = 0; j < val; j++) s+=c;
            
            if(c =='.') c ='#';
            else c = '.';
        }
        a[i] = s;
        // cout << s << " " << s.size() << " " << i << "\n";
    }
    bool error = false;
    for(int i = 1; i < n; i++){
        if(a[i].size() != a[i-1].size()){
            error = true;
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << "\n";
    if(error) cout << "Error decoding image\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    string dummy;
    int x = 0;
    while(cin >> n && n != 0){
        if(x) cout << "\n";
        x = 1;
        getline(cin,dummy);
        solve(n);
        
    }
}