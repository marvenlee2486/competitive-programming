#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string mode, s;
    cin >> n >> mode >> s;
    int m;
    if(mode == "left-over-middle") m = 0;
    else m = 1;
    int pos[] = {0, 4, 8};
    int rel[] = {0,1,2};
    string out = ".........";
    for(int j = 0; j < 3; j++) out[pos[j]] = s[j];
    cout << out << "\n";
    for(int i = 0; i < n; i++){
        for(int r = 0; r < 4; r++){

            string out = ".........";
            if(m == 0){
                pos[rel[0]]++;
                pos[rel[1]]--;
            }
            else{
                pos[rel[1]]++;
                pos[rel[2]]--;
            }
            
            out[pos[rel[1]]] = s[rel[1]];
            out[pos[rel[0]]] = s[rel[0]];
            out[pos[rel[2]]] = s[rel[2]];
            cout << out << "\n";
        }
        if(m == 0) swap(rel[0],rel[1]);
        else swap(rel[1], rel[2]);
        m = 1 - m;
    }
}