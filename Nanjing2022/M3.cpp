#include<bits/stdc++.h>
using namespace std;
using pt = complex<int>;
#define x() real()
#define y() imag()
const int none = 1e5;
void solve(){
    int n;
    cin >> n;
    vector<pt> poly;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        poly.emplace_back(x, y);
    }
    int ans = 0;
    int x = -1;
    int st = none;
    for(int i = 0; i < n; i++){
        pt pt1 = poly[(i - 1 + n) % n], pt2 = poly[i], pt3 = poly[(i + 1) % n];

        pt v1 = pt2 - pt1, v2 = pt3 - pt2;
        /cout << v1.x() << " " << v1.y() << " " << v2.x() << " " << v2.y() << " ";
        if(v1.y() < 0 && v2.y() > 0 && (conj(v1) * v2).y() > 0) {
            cout << i << " FIRST\n";
            ans++;
        }
        else if(v1.y() < 0 && v2.y() == 0) {
            st = pt2.x();
            cout << i << " SECOND\n";
        }
        else if(v1.y() == 0 && v2.y() > 0 && pt2.x() > st){
            cout << i << " THIRD\n";
            ans++;
            st = none;
        }
        else if(v1.y() == 0 && v2.y() == 0) {
            cout << i << " FOURTH\n";
            continue;
        }
        else {
            cout << i << " FIFTH\n";
            st = none;
        }
        
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}