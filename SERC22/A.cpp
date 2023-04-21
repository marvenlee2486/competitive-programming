#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s,t;
    cin >> s >> t;
    int n = s.size();
    int a[n][26];

    for(int i = 0; i < n; i++){
        for(int c = 0; c < 26; c++){
            int j = i + 1;
            if(j >= n) j = 0;
            a[i][c] = -1;
            if(s[i] == 'a' + c) a[i][c] = i;
            while(j != i){
                //cout << i << " " << j << "\n";
                
                if(s[j] == 'a' + c) {
                    a[i][c] = j;
                    break;
                }
                j++;
                if(j >= n) j = 0;
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << s[i] << " ";
    //     for(int j = 0; j < 26; j++) cout << a[i][j] << " ";
    //     cout << "\n";
    // }

    int ans = 1, cur = -1;
    for(char c: t){     
        if(cur == -1){
            for(int i = 0; i < n; i++){
                if(s[i] == c){
                    cur = i;
                    break;
                }
            }
        }
        else{
            int next = a[cur][c - 'a'];
            // cout << cur << " " << next << " " << c << "\n";
            if(next <= cur) ans++;
            cur = next;
            assert(next != -1);
        }
    }
    cout << ans << "\n";

}