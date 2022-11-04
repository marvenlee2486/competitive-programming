#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

typedef complex<double> point;
#define x() real()
#define y() imag()
const long double PI = acos(-1);

point rotation(point a, double theta){
    return a * polar(1.0, theta);
}

void solve(){
    double a,b,r,d;
    cin >> a >> b >> r >> d;
    if(d>90) d = 90;
    point fixed = rotation(point(-r,0), d * PI/180) ;
    point vec2 = rotation(fixed, - PI/2) *b/r  ;
    point vec1 = fixed * a/r;
    long double ans = abs(fixed + vec1 + vec2);

    long double p = a*a + b*b + r*r + 2*b*a;
    p = sqrt(p) - r ;
    ans = min(p,ans);
    cout <<  setprecision(10) <<  ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
    solve();
}