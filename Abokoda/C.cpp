#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main(){
    ll n,q; ld i;
    cin >> n >> q;
    // 2 + 3 + 4 + 5 + ... + n + 1.
    // 1 - 2
    // 3 - 5

    // ith term = i * (i + 3)/2 - i
    /*
    i * i + i = 2 * given
    i ^2 + i - 2 * given = 0
    */
    while(q--){
        cin >> i;
        ld x = sqrt(1 + 8 * i) - 1;
        x /= 2;
        ll term = (ll)x;
        if(term > n){
            cout << "Codemas is already over!\n";
            continue;
        }
        i -= term * (term + 3)/ 2 - term;
        if(i == 0){
            string ss = "th";
            if(term % 10 == 1 && term % 100 != 11) ss = "st";
            else if(term % 10 == 2 && term % 100 != 12) ss = "nd";
            else if(term % 10 == 3 && term % 100 != 13) ss = "rd";
            cout << "On the " << term << ss << " day of Codemas, my computer gave to me,\n";
        }
        else if(i == term){
            if(term == 1) cout << "A syntax error on line three!\n";
            else cout << "And a syntax error on line three!\n";
        }
        else{
            ll num = term - i + 1;
            if(num == 5) cout << "FIVE! COMPILER! WARNINGS!!!\n";
            else cout << num << " compiler warnings,\n";
        }
    }

}