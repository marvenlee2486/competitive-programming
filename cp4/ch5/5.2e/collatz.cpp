#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll next(ll x){
    if(x % 2) return 3 * x + 1;
    else return x / 2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll a,b;
    while(cin >> a >> b && a>0){
        unordered_map<ll,ll> st1;
        unordered_map<ll,ll> st2;
        ll ora = a , orb = b;
        ll idx = 0;
        st1[a] = 0;
        st2[b] = 0;

        while(st2.find(a) == st2.end() && st1.find(b) == st1.end()){
            idx++;
            a = next(a);
            b = next(b);
            if(st1.find(a) == st1.end()) st1[a] = idx;
            if(st2.find(b) == st2.end()) st2[b] = idx;
            
        }
        if(st2.find(a) != st2.end() && st1.find(b) != st1.end()){
            if(st2[a] <= st1[b]){
                printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", ora, idx ,orb, st2[a], a);
            }
            else {
                printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", ora, st1[b] ,orb, idx, b);
            }
        }
        else if(st2.find(a) != st2.end()){
            printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", ora, idx ,orb, st2[a], a);
        }
        else {
            printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", ora, st1[b] ,orb, idx, b);
        }
    }
}