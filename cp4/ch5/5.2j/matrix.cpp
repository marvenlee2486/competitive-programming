#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a,b,c,d;
    int t = 1;
    while(cin >> a){
        cin >> b >> c >> d;
        
        int det = a*d - b*c;
        cout << "Case " << t << ":\n";
        cout << d/det << " " << -1 * b/det << "\n" << -1 * c/det << " " << a/det << "\n";
        t++;
    }
}