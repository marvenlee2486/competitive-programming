#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

typedef complex<long double> point;
#define x() real()
#define y() imag()
const long double PI = acos(-1);

bool compareX(const pair<point,int>& l, const pair<point,int>& r){
    point left = l.first, right = r.first;
    return( left.x() < right.x() || (left.x() == right.x() && left.y() <= right.y()));
} 
bool compareY(const pair<point,int>& l, const pair<point,int>& r){
    point left = l.first, right = r.first;
    return( left.y() < right.y() || (left.y() == right.y() && left.x() <= right.x()));
}

void solve(){
    int x1,y1,x2,y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    long double ans = abs(remainder(arg(point(x1,y1)) - arg(point(x2,y2)), 2.0 * PI));
    if(ans <0) ans = -ans;
    cout << fixed << setprecision(10) << ans   << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    
    solve();
}