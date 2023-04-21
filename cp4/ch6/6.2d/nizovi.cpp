#include<bits/stdc++.h>
using namespace std;          

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int level = 0;
    int st = 0;
    for(char c:s){
        if(st || c== '}'){
            cout << "\n";
            if(c=='}'){
                level--;
            }
            for(int j = 0; j < level; j++) cout << "  ";
            st = 0;
        }
        cout << c;
        if(c == '{') {
            level++;
            st = 1;
            
        }
        else if(c == ','){
            st = 1;
        }
    }
    cout << "\n";
}