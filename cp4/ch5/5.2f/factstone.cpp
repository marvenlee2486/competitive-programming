#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int p;
    while(cin >> p && p){
        ll bin = (p - 1940)/10;
        bin = pow(2, bin);
        // cout << bin << " ";
        ld ans = 0;
        int i = 1;
        while(ans < bin){
            ans += log2(i);
            i += 1;
        }
        cout << i - 2 << "\n";
    }

}