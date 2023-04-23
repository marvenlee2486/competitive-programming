#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
#define ld long double

#define EPS 1e-8
ll a,b;


void solve2(ll x,ll y, ll z, ll n){
    // ax + by = z
    // a + b <= n
    if(z<0) return;


}

void solve(){
    a=-1,b=-1;

    ll n,d,fc,fe;
    cin >> n >> d >> fc >> fe;
    char p;
    cin >> p;
    if(p=='C'){
        if( n == 1){
            if( d-fc == 0) a=0,b=0;
        }else if(fc * (n-1) == d-fc) {
            a = n-1,b=0;

        }
        else if(fe * (n-1) == d-fc){
            a = 0, b = n-1;
        }
        else solve2(fc,fe,d-fc,n-1);
        
    }else if(p=='E'){
        if( n == 1){
            if( d-fe == 0) a=0,b=0;
        }
        else if(fc * (n-1) == d-fe) {
            a = n-1,b=0;

        }
        else if(fe * (n-1) == d-fe){
            a = 0, b = n-1;
        }
        else solve2(fc,fe,d-fe,n-1);
    }

    if(a <0 || b <0) cout << "IMPOSSIBLE\n";
    else{
        for(int i = 0; i < n;i ++) cout << "P";
        cout << "\n";
        for(int i = 0; i < a;i ++) cout << "R";
        for(int i = 0; i < b;i ++) cout << "S";
        for(int i = 0; i < n-a-b-1; i++) cout << "P";
        if(p =='C') cout << "R";
        else cout << "S";
    } 

     
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
