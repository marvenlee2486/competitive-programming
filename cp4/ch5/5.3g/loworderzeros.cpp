#include<bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<int,int> dp;

/*
Let D(n) be the last non-zero digit in n!
If tens digit (or second last digit) of n is odd
    D(n) = 4 * D(floor(n/5)) * D(Unit digit of n) 
If tens digit (or second last digit) of n is even
    D(n) = 6 * D(floor(n/5)) * D(Unit digit of n)
*/
int recur(int n){
    if(n < 10) return dp[n];
    if(dp.find(n) != dp.end()) return dp[n];
    if( (n / 10 ) % 2 ){
        return dp[n] = (4 * recur(n/5) * recur(n % 10)) % 10;
    } else{
        return dp[n] = (6 * recur(n/5) * recur(n % 10)) % 10;
    }
}

int main(){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 6;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 2;
    dp[7] = 4;
    dp[8] = 2;
    dp[9] = 8;

    int n;
    while(cin >> n && n){
        cout << recur(n) << "\n";
    }
}