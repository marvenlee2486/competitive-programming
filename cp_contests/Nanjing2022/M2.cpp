#include<bits/stdc++.h>
using namespace std;
using pt = complex<int>;
using ii = pair<int,int>;
void solve(){
    int n;
    cin >> n;
    unordered_map<int, vector<ii> > plat;
    vector<pt> in, out;
    vector<pt> poly;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        poly.emplace_back(x, y);
        plat[y].emplace_back(x, i);
    }

    // for(int i = 0; i < n; i++){
    //     pt p1 = poly[(i - 1 + n) % n], p2 = poly[i], p3 = poly[(i + 1) % n];

    //     in.emplace_back(p1);
    //     out.emplace_back(p3);
    // }
    int ans = 0;
    for(auto&[__, check]: plat){
        sort(check.begin(), check.end());
        reverse(check.begin(), check.end());
        int cnt = 0;
        for(auto&[_,idx]:check){
            // cout << in[idx].real() << " " <<  in[idx].imag() << " " << out[idx].real() << " " << out[idx].imag() << "\n";
            // if(in[idx].real() >= 0 && out[idx].real() >= 0) continue;
            // if(in[idx].imag() > 0 && out[idx].imag() > 0) ans++;
            // else if( min(in[idx].imag(), out[idx].imag()) == 0 && max(in[idx].imag(), out[idx].imag()) > 0){
            //     cnt++;
            //     if(cnt == 2){
            //         cnt = 0;
            //         ans++;
            //     }
            // }
            // else if( min(in[idx].imag(), out[idx].imag()) < 0 && max(in[idx].imag(), out[idx].imag()) == 0){
            //     cnt = 0;
            // }
            pt p3 = poly[(idx - 1 + n) % n], p2 = poly[idx], p1 = poly[(idx + 1) % n];
            if(p1.real() < p2.real() || p3.real() > p2.real()) {
                cnt = 0;
                continue;
            }
            // cout << idx << " ";
            if(p1.imag() > p2.imag() && p3.imag() > p2.imag()) ans++;
            else if(p1.imag() > p2.imag() && p3.imag() == p2.imag()){
                cnt++;
            }
            else if(cnt == 1 && p1.imag() == p2.imag() && p3.imag() > p2.imag()){
                ans++;
                cnt = 0;
            } else if(cnt == 1 && p1.imag() == p2.imag() && p3.imag() < p2.imag()  ) cnt = 0;
        }
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}