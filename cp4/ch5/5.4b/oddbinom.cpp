/*
0 o 
0 o o
0 o e o
2 o o o o
0 o e e e o
2 o o e e o o
2 o e o e o e o
6 o o o o o o o o 
0 o e e e e e e e o
2 o o e e e e e e o o
2 o e o e e e e e o e o
6 o o o o e e e e o o o o
2 o e e e o e e e o e e e o
6 o o e e o o e e o o e e o o
6 o e o e o e o e o e o e o e o
14 o o o o o o o o o o o o o o o o

*/

// 2
// 2 2 6 
// 2 2 6 2 6 6 14
// 2 2 6 2 6 6 14 

/*
a(0) = 0, a(1) = 1, a(2k) = 3*a(k), a(2k+1) = 2*a(k) + a(k+1). 
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll recur(ll n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n % 2) return 2 * recur(n / 2) + recur(n / 2 + 1);
    else return 3 * recur(n / 2);
}

int main(){
    // init();
    // for(int i = 0; i < 31; i++){
    //     int cnt = 0;
    //     for(int j = 0; j <= i; j++){
    //         cout << bin[i][j]%2 << " ";
    //         cnt += bin[i][j] % 2;
    //     }
    //     cout << cnt << "\n";
    // }
    ll n;
    cin >> n;
    cout << recur(n) << '\n';



}

/*
1
10
11 = 4
100
101
110
111 = 8, 2 ^ 3
1000
1001
1010
1011
1100
1101
1110
1111 = 20
*/