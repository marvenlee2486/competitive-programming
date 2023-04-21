#include<bits/stdc++.h>
using namespace std;
using pt = complex<int>;
#define x() real()
#define y() imag() 
int cross_product(pt p1, pt p2){
    // cout << "CROSS " << p1.x() << " " << p1.y() << " " << p2.x() << " " << p2.y() << "\n";
	return p1.x() * p2.y() - p2.x() * p1.y();
}
bool ok(pt p1, pt p2, pt p3, bool how){
    // cout << p1.x() << " " << p1.y() << " " << p2.x() << " " << p2.y() << " " << p3.x() << " " << p3.y() << "\n";
    // cout << cross_product(p3-p1, p2-p1) << "\n";
    if(how) return cross_product(p3-p1, p2-p1) >= 0;
    else return cross_product(p3-p1, p2-p1) <= 0;
}

int dir(pt p1, pt p2){
    int x =  (p2 - p1).x();
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}

/*
7
1 0
3 4
0 3
1 2
2 3
2 2
0 2


*/

void solve(){
    int n;
    cin >> n;
    vector<pt> poly;
    bool check[n];
    memset(check, 0 , sizeof check);
    vector<pair<pt,int> > sorting;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        poly.emplace_back(x, y);
        sorting.emplace_back(poly.back(), i);
    }
    sort(sorting.begin(), sorting.end(), [&](auto l, auto r){
        return l.first.y() < r.first.y() || (l.first.y() == r.first.y() && l.first.x() < r.first.x());
    });
    // cout << "HERE?\n";
    int ans = 0;
    for(auto&[point, idx]: sorting){
        if(check[idx]) continue;
        // cout << idx << "\n";
        // cout << "HERE?\n";
        vector<bool> temp(n, 1);
        // Counter
        pt prev2 = pt(0,0);
        pt prev = poly[idx];
        int y = prev.y();
        bool gg = false;
        // cout << "CHECLINMG " << idx << "\n";
        //cout << "COUNTER\n";
        for(int i = idx + 1; i != idx; i++){
            
            if(i == n) i = 0;
            if(i == idx) break;
            //if(!gg && !ok(prev2, prev, poly[i], false) && poly[i].y() < prev.y() && dir(prev,poly[i]) > 0 && dir(poly[i], poly[ (i + 1 )%n]) > 0){
            pt cur = poly[i];
            pt next = poly[(i+1)%n];
            if(dir(prev,poly[i]) > 0 && dir(cur, next) >= 0 && next.y() >= cur.y() && cur.y() < prev.y() ){
                gg = true;
            }
            
            // if(gg && poly[i].y() >= y){
            //     gg = false;
            // }

            if(gg) temp[i] = 0;

            // cout << i << " " << gg << "\n";
            gg = false;
            prev2 = prev;
            prev = poly[i];
        }

        prev2 = pt(0,0);
        prev = poly[idx];
        y = prev.y();
        gg = false;
        // cout << "CLOCKWISE\n";
        for(int i = idx - 1; i != idx; i--){
            if(i < 0) i += n;
            if(i == idx) break;
            
            pt cur = poly[i];
            pt next = poly[(i-1 + n)%n];
            if(dir(prev,poly[i]) < 0 && dir(cur, next) <= 0 && next.y() >= cur.y() && cur.y() < prev.y() ){
                gg = true;

            }
            
            if(gg) temp[i] = 0;

            // cout << i << " " << gg << "\n";
            gg = false;
            prev2 = prev;
            prev = poly[i];
        }
        for(int i = 0; i < n; i++){
            // cout << i << " : " << temp[i] << "\n";
            if(temp[i] == 1) check[i] = 1;
        }
        ans++;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
}