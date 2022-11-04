#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

typedef complex<long double> point;
#define x() real()
#define y() imag()
const long double PI = acos(-1);
const long double EPS = 1e-18;
// struct line{
//     double a,b,c;
//     // ax+ by = c;
//     // x cos α + y sin α = p
// };

// long double cot(point a,point b){
//     return (conj(a) * b).x() / (conj(a) * b).y();
// }

long double cot(double angle){
    if(sin(angle)<=EPS) return 0;
    return cos(angle)/sin(angle);
}

void solve(){
    int x1,y1, x2,y2 ,x3 ,y3; 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    point p1(x1,y1),p2(x2,y2),p3(x3,y3);

    double angle = remainder(arg(p2 - p1) - remainder(arg(p2 - p1) - arg(p3 - p1), 2 * PI)/2 , 2* PI);
    cout << angle << "\n";
    cout << fixed << setprecision(10) << cos(angle) << " " << sin(angle) << " " << y1 - cot(angle) * x1 << "\n" ;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    
    solve();
}