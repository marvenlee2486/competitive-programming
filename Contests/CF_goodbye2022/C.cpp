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


// 15

/// under the same difference, you will not have more than 2 elements.
// under the different difference, the xi will confirm be always the same element.

/*

  3 5 15
1 4 6 16
2 5 7 17

Another observation, your difference will never be even.

since odd difference, 1 and 2 will always be ok, so no matter what case just make everythings to be 1..

Now the problem is with even different that in the same difference, they are having the same 
*/


bool solve(){
    int n;
    cin >> n;
    vl a(n, 0);
    for(auto& i: a) cin >> i;
    int sett = -1;
    map<ll, set<ll> > mp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if( abs(a[i] - a[j]) % 2 == 0 ){
                if(sett == -1) sett = a[i] % 2;
                if(sett != a[i] % 2) return false;
            }
            if(mp.find(abs(a[i] - a[j])) == mp.end()) mp[abs(a[i] - a[j])] = set<ll>();
            mp[abs(a[i] - a[j])].insert(min(a[i],a[j]));
            if(abs(a[i] - a[j]) == 0) return false;
        }
    }
    for(auto[x, st]: mp){
        if(st.size() == 2) continue;
        bool test[x];
        test[0] = false;
        for(ll i = 1; i < x; i++){
        test[i] = __gcd((unsigned long long)i,(unsigned long long) n) == 1;
        bool can = false;
        
        for(ll i = 1; i < x; i+=2){
            bool second = true;
            ll pre = *st.begin();
            for(auto c: st){
                ll diff = c - pre;
                if(!test[(i + diff)%x]){
                    second = false;
                    break;
                }
            }
            if(second) {
                can = true;
                break;
            }
        }
        
        if(!can) return false;

    }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) cout << (solve()?"YES\n":"NO\n");
}