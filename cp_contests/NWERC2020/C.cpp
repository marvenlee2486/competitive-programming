#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    double d,s;
    cin >> n >> k >> d >> s;

    double ans = (d*n) - (k*s);
    ans /= (n-k);
    if(ans>100 || ans<0) cout << "impossible\n";
    else cout << fixed << setprecision(7) << ans ;
    
}