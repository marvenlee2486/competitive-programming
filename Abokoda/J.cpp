#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using pt = complex<ld>;
#define x real()
#define y imag()
const ld eps = 1e-9;
const ld PI = acos(-1);
struct answer{
    pt point;
    ld area;
    bool rhom,rec;
    answer(pt point, ld area, bool rhom, bool rec):point(point),area(area),rhom(rhom),rec(rec){}
};

answer gen(pt pt1, pt pt2, pt pt3){
    pt pt4; ld area; bool rhom,rec;
    // pt1 
    pt4 = pt2 + (pt3 - pt1);
    area = fabs((conj(pt2 - pt1) * (pt3 - pt1)).y);
    rhom = norm(pt2 - pt1) == norm(pt3 - pt1);
    rec = fabs(abs(remainder(arg(pt2-pt1) - arg(pt3-pt1), 2.0 * PI)) - PI/2)  < eps;
    return answer(pt4,area,rhom,rec);
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    pt pt1(x1,y1), pt2(x2,y2), pt3(x3,y3);

    vector<answer> ans;
    ans.emplace_back(gen(pt1,pt2,pt3));
    ans.emplace_back(gen(pt2,pt1,pt3));
    ans.emplace_back(gen(pt3,pt1,pt2));
    
    sort(ans.begin(), ans.end(), [](auto left, auto right)->bool{
        return left.point.x < right.point.x || ( (left.point.x == right.point.x) && left.point.y < right.point.y );
    });


    for(answer anss: ans){

        cout << "point: " << fixed << setprecision(2) << anss.point.x  << " " << anss.point.y << "\n";
        cout << "area: " << fixed << setprecision(2) << anss.area << "\n";
        cout << "is rhombus: " << ((anss.rhom)? "yes\n":"no\n");
        cout << "is rectangle: " << ((anss.rec)? "yes\n":"no\n");
        cout << "-------------------------\n";
// area: 2.00
// is rhombus: no
// is rectangle: no
// -------------------------
    }

}