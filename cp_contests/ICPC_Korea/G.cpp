#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct scenario{
    ll s,a,b,c, idx;
    scenario(ll s, ll a, ll b, ll c, ll idx):s(s),a(a),b(b),c(c), idx(idx){}
};

bool compare( const scenario A, const scenario B){
    ll aa,ab,ac,ba,bb,bc,ss,as,bs;
    aa = A.a * B.s;
    ab = A.b * B.s;
    ac = A.c * B.s;

    ba = B.a * A.s;
    bb = B.b * A.s;
    bc = B.c * A.s;

    as = A.s;
    bs = B.s;
    ss = A.s * B.s;

    ll vala = 0, valb = 0;
    vala += 2*(ss - aa)*(aa * ab) + aa * ac * ac;
    vala += 2*(ss - ab)*(aa * ab) + ab * ac * ac;

    vala += 2*(ss - aa)*(aa * ac) + aa * ab * ab;
    vala += 2*(ss - ac)*(aa * ac) + ac * ab * ab;

    vala += 2*(ss - ab)*(ab * ac) + ab * aa * aa;
    vala += 2*(ss - ac)*(ab * ac) + ac * aa * aa;
    
    
    valb += 2*(ss - ba)*(ba * bb) + ba * bc * bc;
    valb += 2*(ss - bb)*(ba * bb) + bb * bc * bc;

    valb += 2*(ss - ba)*(ba * bc) + ba * bb * bb;
    valb += 2*(ss - bc)*(ba * bc) + bc * bb * bb;

    valb += 2*(ss - bb)*(bb * bc) + bb * ba * ba;
    valb += 2*(ss - bc)*(bb * bc) + bc * ba * ba;
    //cout << vala << " " << valb << "\n";
    return (vala < valb) || ((vala == valb) &&  (A.idx < B.idx) );
}
void solve(){
    int n;
    cin >> n;
    vector<scenario> arr;
    for(int i = 0; i < n; i++){
        ll s,a,b,c;
        cin >> s >> a >> b >> c;
        arr.push_back(scenario(s,a,b,c, i+1));
    }

    sort(arr.begin(), arr.end(), compare);
    // reverse(arr.begin(),arr.end());
    for(int i = 0; i < n; i++){
        cout << arr[i].idx << " ";
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  
  while(t--) solve();
  return 0;
}

