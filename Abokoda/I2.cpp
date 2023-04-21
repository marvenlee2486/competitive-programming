#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a[n];
    string s;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    int pos = 0;
    /*
          1 2
        0     3
        7     4
          6 5

    */
    reverse(s.begin(),s.end());
    for(char c : s){
        if(c == 'R') pos -= 2;
        else if(c == 'L') pos += 2;
        else if(c == 'H'){
            if(pos < 4) pos = 3 - pos;
            else pos = 11 - pos;
        }
        else{
            pos = 7 - pos;
        }
        if(pos < 0) pos += 8;
        if(pos > 7) pos -= 8;
    }
    // cout << pos << "\n";
    if(pos % 2 == 1){
        if(pos == 3){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n/2; j++){
                    swap(a[i][j], a[i][n - j - 1]);
                }
            }
        }
        else if(pos == 5){
            string an[n];
            for(int i = 0; i < n; i++){
                an[i] = a[i];
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[j][n - i - 1] = an[i][j];
                }
            }
            for(int i = 0; i < n/2; i++){
                for(int j = 0; j < n; j++){
                    swap(a[i][j], a[n - i - 1][j]);
                }
            }
        }
        else if(pos == 7){
            for(int i = 0; i < n/2; i++){
                for(int j = 0; j < n; j++){
                    swap(a[i][j], a[n - i - 1][j]);
                }
            }
        }
        else {
            string an[n];
            for(int i = 0; i < n; i++){
                an[i] = a[i];
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[j][n - i - 1] = an[i][j];
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n/2; j++){
                    swap(a[i][j], a[i][n - j - 1]);
                }
            }
        }
        
    }
    else{
        for(int r = 0; r < pos/2; r++){
            string an[n];
            for(int i = 0; i < n; i++){
                an[i] = a[i];
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[j][n - i - 1] = an[i][j];
                }
            }
        }
    }
    

    for(int i = 0; i < n; i++) cout << a[i] << "\n";

}