#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int d, r , x;
    cin >> d >> r >> x;
    int t = r + x;
    int age = 4;
    int cur = 0;
    int exp = 0;
    while(cur < t){
        //cout << cur << " " << t << "\n";
        cur += age;
        if(age - d >= 3) cur += age - d;
        exp += age;
        age++;
    } 
    cout << r - exp << "\n";

}