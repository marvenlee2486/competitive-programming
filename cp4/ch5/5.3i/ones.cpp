/*
11 =  11
111 = 3 * 37
1111 = 11 * 101
11111 = 41 * 271
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ans = 0;
        int cur = 0;
        do{
            cur *= 10;
            cur += 1;
            ans ++;
            cur %= n;
        }while(cur != 0);
        cout << ans << "\n";
    }   
}