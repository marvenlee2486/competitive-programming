#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main(){
    int n;
    while(cin >> n && n){
        vector<ld> a(n, 0);
        for(auto& i: a) cin >> i;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            a[i] *= 100;
            sum += a[i];
        }
        ll minus = 0;
        if(sum %n != 0) minus = 1;
        sum /= n;
        ld need = 0;
        for(int i = 0; i < n; i++) need += abs(a[i] - sum - minus);
        // cout << sum << "\n";
        // cout << need << "\n";
        need /= 100;
        cout << "$" << fixed << setprecision(2) << need << "\n";
    }
}