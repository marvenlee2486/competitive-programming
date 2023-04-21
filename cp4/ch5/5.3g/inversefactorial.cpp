#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
/*
solution:

the number of digit of a number x = log10(x) + 1,


the number of digit of n! 
=  log10(n!) + 1
= log10(n) + log10(n - 1) + log10(n - 2) + ... + log10(1) + 1;
*/

int main(){
    int x = 1;
    string s; 
    cin >> s;
    int target = s.size();
    // 1,2,6,24,120,720, 5040, 320 
    if(target <= 5){
        ll x = stol(s);
        int i = 1;
        while(x != 1){

            i++;
            x/=i;
        }
        cout << i << "\n";
        return 0;
    }

    ld cur = 1;
    int n = 1;
    while((int)cur < target){
        n++;
        cur += log10(n);
    }
    cout << n << '\n';

}