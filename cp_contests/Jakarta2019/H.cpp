#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct land{
    ll A,B,idx;
    land(ll A,ll B,ll idx):A(A),B(B),idx(idx){}
};

void solve(){
    int n;
    cin >> n;
    long double ans = 0;
    vector<land> sortA;
    vector<land> sortB;
    vector<land> ori;
    for(int i = 0; i < n; i++){
        ll a,b;
        cin >> a >> b;
        if(a<b) swap(a,b);
        sortA.push_back(land(a,b,i));
        sortB.push_back(land(a,b,i));
        ori.push_back(land(a,b,i));
        ans = max(ans, (long double)a*b*1.0/2);

    }

    sort(sortA.begin(),sortA.end(),[&](auto a,auto b){
        return(a.A > b.A || (a.A == b.A && a.B > b.B));
    }
    );

    sort(sortB.begin(),sortB.end(),[&](auto a,auto b){
        return(a.B > b.B || (a.B == b.B && a.A > b.A));
    }
    );

    ll maxv = sortA[0].B;
    priority_queue<ii> pq;
    pq.push(ii(sortA[1].B,0));
    //cout << ans << "\n";
    for(int i = 1; i < n; i ++){

        while(!pq.empty()){
            if(pq.top().first >= sortA[i].A){
                maxv = max(maxv, sortA[pq.top().second].A);
            }
            else break;
            pq.pop();
        }

        ans = max(ans, (long double) sortA[i].A * min(maxv,sortA[i].B));
        
        maxv = max(maxv, sortA[i].B);
        pq.push( ii(sortA[i].B,i));
    }
    //cout << ans << "\n";
    maxv = sortB[0].A;
    for(int i = 1; i < n; i++){
        ans = max(ans, (long double) sortB[i].B * min(sortB[i].A , maxv));
        maxv = max(maxv, sortB[i].A);
    }
    cout << fixed << setprecision(1) << ans << "\n";

}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;//cin >> t;
    while(t--)
    solve();
}