#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const ll INF = 1e16;
void solve(){

    int n; cin >> n;
    vector<ll> as;
    vector<ii> a;
    vector<ii> b;
    vector<ii> d;
    vector<ll> ans(n,1);
    ll cur = 0,x;
    cin >> x;

    set<ii> ha;
    set<ii> lb;
    for(int i = 0; i < n; i++){
        int dd; cin >> dd;
        cur+= dd;
        a.emplace_back(dd,i);
        as.emplace_back(dd);
        ha.insert(a[i]);
    }

    for(int i = 0; i < n; i++){
        int dd; cin >> dd;
        b.emplace_back(dd,i);
    }

    for(int i = 0; i < n; i++){
        d.emplace_back(b[i].first - a[i].first,i);
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    // sort(b.begin(),b.end());
    sort(d.begin(),d.end());

    for(int i = 0; i < n; i++){
        if(cur <= x) break;
        cur -= a[i].first;
        ans[a[i].second] = 0;
        lb.insert(b[a[i].second]);
        ha.erase(a[i]);
    }
    ll ptrd = 0;
    for(int i = 0; i < n; i++){
        while(ptrd<n && ans[d[ptrd].second] != 1) ptrd++; 
        ll choice1 = (ptrd<n)? d[ptrd].first: INF;
        ll choice2 = (lb.size() != 0 && ha.size() != 0)? lb.begin()->first - ha.rbegin()->first: INF;
        if(cur + min(choice1 , choice2) > x) break;
        if(choice1 <= choice2){
            cur += choice1;
            ans[d[ptrd].second] = 2; // 1 to 2

            ha.erase({as[d[ptrd].second],d[ptrd].second}); // remove 1 to 0 de possibility
            ptrd++; // remove 1 to 2 de possibility
        }
        else{
            cur += choice2;
            ans[ha.rbegin()->second] = 0; // 1 to 0
            ans[lb.begin()->second] = 2; // 0 to 2

            lb.erase(lb.begin());
            //lb.insert(b[ha.rbegin()->second]);

            auto it = ha.end();
            it--;
            ha.erase(it);
            
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
    

}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0);

    solve();
}
