#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int q1(int i){
    cout << "? 1 " << i << endl;
    char c;
    cin >> c;
    return c-'a';
}

int q2(int l, int r){
    cout << "? 2 " << l << " " << r << endl;
    int cnt ; cin >> cnt;
    return cnt;
}


void solve(){
    int n;
    cin >> n;
    int l = 1;
    int last[26];
    char ans[n+1];
    memset(last,-1, sizeof last);

    int dist = 0;
    for(int r = 2; r <= n+1; r++){
        if(r == n+1 || q2(l,r) != 1){
            int val;
            if( dist == 26 || q2(1,r-1) == dist){
                vector<ii> pos;
                for(int i =0;i<26;i++){
                    if(last[i]==-1) continue;
                    pos.emplace_back(last[i],i);
                }
                sort(pos.begin(),pos.end());

                int l1 = 0, r1 = pos.size() - 1;
                // 5 
                while(l1 < r1){
                    int mid = (l1+r1+1)/2;

                    int position = pos[mid].first;
                    if( q2(position,r-1) == pos.size() - mid){
                        l1 = mid;
                    }
                    else{
                        r1 = mid-1;
                    }
                }
                val = pos[l1].second;
                
            } else{
                val = q1(r-1);
                dist++;
                
            }
            for(int i = l; i<r; i++){
                ans[i] = val + 'a';
            }
            last[val] = r-1;
            l = r;
        }
    }
    cout << "! ";
    for(int i = 1; i<=n; i++){
        cout << ans[i] ;
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    int t=1;
    //cin >> t;
    while(t--)
    solve();
}