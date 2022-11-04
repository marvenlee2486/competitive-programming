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

long double cross(point a, point b){
    return  (conj(a) * b).y();
}


void solve(){
    vector<point> polygon;
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    point p1 (x1,y1), p2 (x2,y2), p3(x3,y3);
    long double area = fabs(cross(p2-p1, p3-p1))/2;
    cout << fixed << setprecision(10) << area <<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    
    solve();
}