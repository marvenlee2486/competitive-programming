#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    unsigned int u,d;
    while(cin >> u >> d && d){
        cout << u/d << " " << u % d << " / " << d << "\n";
    }
}