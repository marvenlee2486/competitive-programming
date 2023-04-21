#include<bits/stdc++.h>
using namespace std;
const int N = 2001;
string s[N];
int n;
void change(){
    bool on[3][n];
    memset(on, 0, sizeof on);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(s[i][j] == '1'){
                on[0][i] = 1;
                on[1][j] = 1;
                on[2][i - j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(on[0][i]){
            for(int j = 0; j <= i; j++){
                if(s[i][j] == '1') s[i][j] = '0';
                else s[i][j] = '1';
            }
        }
    }

    for(int j = 0; j < n; j++){
        if(on[1][j]){
            for(int i = n - 1; i >= j; i--){
                if(s[i][j] == '1') s[i][j] = '0';
                else s[i][j] = '1';
            }
        }
    }

    for(int ij = 0; ij < n; ij++){
        if(on[2][ij]){
            // i - j = ij;
            for(int j = 0; j < n; j++){
                int i = ij + j;
                if(j > i || i < 0 || j < 0 || i >= n) continue;

                if(s[i][j] == '1') s[i][j] = '0';
                else s[i][j] = '1';
            }
        }
    }
}
bool special(){
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < i; j++){
            if(s[i][j] == '1') return false;
        }
    }
    for(int i = 2; i < n - 1; i++){
        if(s[i][0] != s[i - 1][0]) return false;
        if(s[i][i] != s[i - 1][i - 1]) return false;
        if(s[n - 1][i] != s[n - 1][i - 1]) return false;
    }
    return true;
}
bool check(){
    if(special()) return true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            if(s[i][j] == '1') return false;
        }
    }
    return true;
}

void print(){
    for(int i = 0; i < n; i++){
        cout << s[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    if(check()){
        cout << "YES\n";
        return 0;
    }
    for(int t = 0; t <= n; t++){
        change();
        if(check()){
            cout << "YES\n";
            return 0;
        }
        cout << "Iteration " << t << ":\n";
        print();
    }
    cout << "NO\n";
    return 0;
}