#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool q(int l, int r){
    cout << "? " << l << " " << r << endl;
    int cnt = 0;
    for(int i = l ; i <= r; i++){
        int x;
        cin >> x;
        if(x >= l && x <=r) cnt ++;
    }
    return cnt%2;
}


void solve(){
    int n;
    cin >> n;
    int l = 1, r=n;
    while(l<r){
        int mid = (l+r)/2;

        if(q(l,mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << "! " << l << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    solve();
}