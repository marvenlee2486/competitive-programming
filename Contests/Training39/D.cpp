#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
#define all(x) x.begin(),x.end()
#define FOR(i, a, b) for (ll i = a; i <= b; ++i) 
#define chkmax(x, a) x = max(x, a)
struct pt{
    double x, y;
    pt(double x, double y): x(x),y(y){}
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

vector<pt> convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    return st;
}

int sign(int x){
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
}

void solve(){
    set<ii> ptss;
    vector<pt> original;
    int n;
    cin >> n;
    if(n==1){
        int x,y;
        cin >> x >> y;
        cout << "4\n";
        return;
    }
    // else if(n==2){
    //     int x1,y1,x2,y2;
    //     cin >> x1 >> y1 >> x2 >> y2;
        
    // }
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        ptss.insert(ii(x,y));
        ptss.insert(ii(x-1,y));
        ptss.insert(ii(x+1,y));
        ptss.insert(ii(x,y-1));
        ptss.insert(ii(x,y+1));
        original.push_back(pt(x,y));
    }
    vector<pt> pts;
    for(auto e: ptss) pts.emplace_back(pt(e.first,e.second));
    vector<pt> ans = convex_hull(pts,false);
    ll che = 0;

        //cout << ans[0].x << " " << ans[0].y << "\n";
    for(int i = 1; i < ans.size(); i++){
        //cout << ans[i].x << " " << ans[i].y << "\n";
        che += max(abs(ans[i].x - ans[i-1].x) , abs(ans[i].y - ans[i-1].y));
    }
    che += max(abs(ans[0].x - ans.back().x) , abs(ans[0].y - ans.back().y));
    
    sort(original.begin(),original.end(), [&](auto l,auto r){
        return l.x < r.x || (l.x == r.x && l.y < r.y);
    });
    bool can = !(abs(original[1].y - original[0].y) != abs(original[1].x - original[0].x));
    for(int i = 2; i < n; i++){
        if( abs(original[i].y - original[i-1].y) != abs(original[i].x - original[i-1].x) || 
            !( sign(original[i].y - original[i-1].y) == sign(original[i-1].y - original[i-2].y) &&
                sign(original[i].x - original[i-1].x)%2  == sign(original[i-1].x - original[i-2].x))
        ){
            can = false;
            break;
        }
    }
    if(can){
        che += 1;
    }
   
    cout << che << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
