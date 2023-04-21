#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using ld = long double;
using vl = vector<ll>;

#define rep(i,a,b) for(int i = (a); i < (b); i++)
// rmb make all __gxd = 1; meaning all are coprime with each other,
// if 2 even or 2 odd = NO,
// case 1 or 0 even, all odd, or 1 or 0 odd, all even

// got diff 0 , confirm cannot;
// /// 1 - always 1
// /// 2 - every 2
// /// 3 - every 3
// /// 4 - every 2
// /// 5 - every 5
// /// 6 - every 

// 1 7 ok 
// 2 8 (not 1)
// 3 9 (not 1)
// 4 10 (not 1)
// 5 11 ok
// 6 12 Not 
// 7 13 ok  
// 8 14 not (1)
// 9 15 not 

// % 2 
// % 3 

// 4 - 0 2 
// 6 - 0 2 4 
// 8 - 0 2 4 6
// 9
// 10 - 0 2 4 6 8 

// 1 10 (OK)
// 2 11 (OK)
// 3 12
// 4 13 (OK)
// 5 14 (OK)
// 6 15
// 7 16 (OK)
// 8 17 (OK)
// 9 18 


// n ^ 2; can expressed as 
// xi % diff

// if( __gcd(diff,xi) == 1) ok for all i;



// 1 + x % 2
// 0 + x % 5
// 1 + x % 3

// find if there is such x, such that all __gcd of( ) == 1;


void solve(){
    int n;
    cin >> n;
    bool test[n];
    test[0] = false;
    for(int i = 1; i < n; i++){
        test[i] = __gcd((unsigned int)i,(unsigned int) n) == 1;
    }
    bool can = false;
    for(int i = 1; i <= n; i++){
        // can = false;
        // for(int j = 0; j < n; j++){
        //     if(test[j] && test[(j+i)%n]) can = true;
        // }
        // if(!can) cout << i << "th cannot\n";

        cout << i << " ";
        if(test[i%n]) cout << "OK";
        cout << "\n";
    }
    cout << "\n";
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(true) solve();
}