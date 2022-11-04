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
    int x,y; 
    cin >> x >> y;
    long double ans = arg(point(x,y));
    if(ans <0) ans += 2* PI;
    cout << fixed << setprecision(10) << ans   << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("angle1.in", "r", stdin);
    freopen("angle1.out", "w", stdout);
    
    solve();
}