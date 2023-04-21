#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD = 1e9 + 7;

void solve(){
   int r, c;
   cin >> r >> c;
   string arr[r];
   
   for(int i = 0; i < r; i ++) cin >> arr[i];
    bool can = false;
    bool zero = true;
    bool corner = false;
    bool wall = false;
    bool full = false;
    bool one = false;
    for(int i=0;i<r;i++){
        bool fullflag = true;
        for(int j = 0; j < c ; j ++){
            if(arr[i][j] == 'A') {
                can = true;
                if(i==0||i==r-1||j==0||j==c-1) wall = true;
                if((i==0||i==r-1) && (j==0||j==c-1)) corner = true;
            }
            else {
                zero = false;
                fullflag = false;
            }

        }
        if(fullflag && (i==0||i==r-1)) one = true;
        else if(fullflag) full = true;
    }

    for(int j = 0; j < c; j++){
        bool fullflag= true;
        for(int i = 0; i < r; i ++){
            if(arr[i][j] != 'A'){
                fullflag = false;
                break;
            }
        }
        if(fullflag && (j==0||j==c-1)) one = true;
        else if(fullflag) full = true;
    }
    

    if(!can) cout << "MORTAL\n";
    else if(zero) cout << "0\n";
    else if(one) cout << "1\n";
    else if(corner || full) cout << "2\n";
    else if(wall && (r==1||c==1)) cout << "2\n";
    else if(wall) cout << "3\n";
    else  cout << "4\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("angle1.in", "r", stdin);
    //freopen("angle1.out", "w", stdout);
    int t=1;
    cin >> t;
    while(t--)
    solve();
}