#include<bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int k;
    cin >> k;
    int idx = 0;
    int sm = -1;
    for(int i = 0; i < 32; i++){
        if(k & (1 << i) ) {
            idx = i;
            if(sm == -1) sm = i;
        }

    }
    
    cout << pow(2, idx + (idx != sm) ) << " " << idx - sm + (idx != sm) << "\n";


}