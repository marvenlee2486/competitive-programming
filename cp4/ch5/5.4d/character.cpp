#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int ans = (1 << n) - (n + 1);
    cout << ans << '\n';
}