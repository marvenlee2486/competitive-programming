#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll low, high = 0;
  cout.fill('0');
  while(cin >> low >> high && low){
    ld ans = 0;
    for(ll i=low; i<=high ;i++){
        ld sq = i*i;
        sq = cbrtl(sq);
        sq = 1/sq;
        ans += sq;
    }
    ans /=3.0;
    ll exp = log10(ans);
    ll ea = abs(exp) +15;
    while(exp<0){
        ans *=10;
        exp ++;
    }
    while(exp>0){
        ans /=10;
        exp--;
    }
    if( ((int)ans) == 0){
        ans*=10;
        ea++;
    }
    cout  << fixed << setprecision(5) << ans << "E-";
    cout  <<  setw(3)  << abs(ea) << "\n";
  }
}