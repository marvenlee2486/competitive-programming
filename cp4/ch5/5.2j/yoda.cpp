#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll x,y;
    cin >> x >> y;
    ll dx = 1;
    ll dy = 1;
    ll lx = 0, ly = 0;
   
    while(x != 0 || y != 0){
        // cout << x << " " << y << "\n";
        if(x % 10 == y % 10){
            lx += dx * (x%10);
            ly += dy * (y%10);
            dx *= 10;
            dy *= 10;
        }
        else if(x % 10 > y % 10){
            lx += dx * (x%10);
            dx *= 10;
        }
        else{
            ly += dy * (y%10);
            dy *= 10;
        }
        x /= 10;
        y /= 10;
    }
    if(dx == 1) cout << "YODA\n";
    else cout << lx << "\n";

    if(dy == 1) cout << "YODA\n";
    else cout << ly << "\n";
}