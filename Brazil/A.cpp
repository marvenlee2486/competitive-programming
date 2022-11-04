#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> ii;

int main(){
    long double ans = 0;
    long double prev = 1;
    long double pro = 1;
    ans += prev*pro*20;
    for(int i = 0; i<20;i++) pro *=0.3;
    for(int i= 21;i<=100;i++){
        pro*=0.3;
        long double now = prev*(i-1) + (long double)(i*(i-1)/2);
        prev = now;
        now *= pro;
        ans += now*i;
        
        cout << ans << "\n";
    }


    return 0;
}