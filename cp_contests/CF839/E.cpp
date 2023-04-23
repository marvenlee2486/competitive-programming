#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(auto &i: a) cin >> i;
    int first = 0, second = 0, shared = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != i + 1 && a[i] != n - i) shared++;
        else if(a[i] != i + 1) first ++;
        else if(a[i] != n - i) second ++;
    }
    //cout << first << " " << second << " " << shared << '\n';
    // int minv = min(first,second);
    // second -= minv;
    // first -= minv;
    if(first + shared <= second) cout << "First\n";
    else if(second + shared < first) cout << "Second\n";
    else cout << "Tie\n";
    // minv = min(max(second, first), shared);
    // shared -= minv;
    // if(second) second -= minv;
    // if(first) first -= minv;

    // if(shared != 0 || shared == 0 && second == 0 && first == 0) cout << "Tie\n";
    // else if(first) cout << "Second\n";
    // else cout << "First\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}

