#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a[n];
    string s;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    int rotate = 0, h = 0, v = 0;
    for(char c : s){
        if(c == 'H') h++;
        else if(c == 'V') v++;
        else if(c == 'L') rotate++;
        else rotate--;
    }
    h %= 2;
    v %= 2;
    rotate = (rotate % 4 + 4)% 4;
    if(v){
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                swap(a[i][j], a[n - i - 1][j]);
            }
        }
    }
    if(h){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(a[i][j], a[i][n - j - 1]);
            }
        }
    }
    for(int r = 0; r < rotate; r++){
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

    for(int i = 0; i < n; i++) cout << a[i] << "\n";

}