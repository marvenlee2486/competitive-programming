#include<bits/stdc++.h>
using namespace std;
using ld = long double;
const ld eps = 1e-9;
pair<ld,ld> poly(ld a, ld b, ld c){
    //cout << a << " " << b << " " << c << '\n';
    if(b*b - 4 * a * c < 0 || fabs(a) <= eps ) return {-1,-1};
    ld x1 = (-1 * b + sqrt(b*b - 4 * a * c)) / (2 * a);
    ld x2 = (-1 * b - sqrt(b*b - 4 * a * c)) / (2 * a);
    // cout <<  2 * a * x1 + b << "\n";
    // cout <<  2 * a * x2 + b << "\n";
    if( 2 * a * x1 + b < 0) swap(x1,x2);
    return {x1 ,x2};
}

ld val(ld p[], ld x){
    ld res = p[0] + p[1] * x + p[2] * x * x + p[3] * x * x * x;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ld b[4], d[4], t[4], f[4];
    while(cin >> b[0] >> b[1] >> b[2] >> b[3]){
        cin >> t[0] >> t[1] >> t[2] >> t[3];

        for(int i = 0; i < 4; i++) d[i] = (t[i] - b[i]) * i, f[i] = (t[i] - b[i]);

        ld x1, x2;
        tie(x1, x2) = poly(d[3], d[2], d[1]);
        // cout << x1 << " " << x2 << "\n";
        if(x1 < 0 || x1 > 1){
            if(val(f,1) > val(f,0)) x1 = 0;
            else x1 = 1;
        }

        if(x2 < 0 || x2 > 1){
            if(val(f,1) > val(f,0)) x2 = 1;
            else x2 = 0;
        }
        // cout << x1 << " " << x2 << "\n";
        ld ans = x2 * x2 * x2 * f[3] + x2 * x2 * f[2] + x2 * f[1] + f[0]
        - (x1 * x1 * x1 * f[3] + x1 * x1 * f[2] + x1 * f[1] + f[0]);
        cout << fixed << setprecision(10) << fabs(ans) << "\n";

    }
}