#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using ld = long double;
const ll maxv = 500;

int gcd(int a, int b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ii> arr;
    for(int i = 2; i < maxv; i++){
        for(int d = i-1; d > 1; d--){
            int x = i;
            int y = i - d;
            
            if(gcd(x,y)!=1) continue;

            arr.emplace_back(x,y);
            arr.emplace_back(y,x);
        }
    }
    sort(arr.begin(), arr.end(),[&](auto x, auto y){
        return (x.first+x.second) < (y.first + y.second);
    });
    
    

    int x = 2 * 1e7 ,y = 1e5;
    int cnt = n/4 + 1;
    sort(arr.begin(), arr.begin() + cnt,[&](auto x, auto y){
        return 1.0 * x.second/x.first < 1.0 * y.second/y.first;
    });
    for(int i = 0; i < cnt; i++){
        x += arr[i].first;
        y += arr[i].second;
        if( n % 4 <= 3 && i ==0) continue;
        cout << x  << " " << y << "\n";
        
        assert(x>=0 && x <= 4 * 1e7 && y >= 0 && y <= 4 * 1e7);
        
    }
    for(int i = cnt - 1; i >= 0; i--){
        x -= arr[i].first;
        y += arr[i].second;
        if( n % 4 <= 2  && i ==0) continue;
        cout << x  << " " << y << "\n";
        assert(x>=0 && x <= 4 * 1e7 && y >= 0 && y <= 4 * 1e7);
        
    }

    for(int i = 0; i < cnt; i++){
        x -= arr[i].first;
        y -= arr[i].second;
        if(n%4 <= 1  && i ==0) continue;
        cout << x  << " " << y << "\n";
        assert(x>=0 && x <= 4 * 1e7 && y >= 0 && y <= 4 * 1e7);
        
    }

    for(int i = cnt - 1; i >= 0; i--){
        x += arr[i].first;
        y -= arr[i].second;

        if(n%4 <= 0 && i ==0) continue;
        cout << x  << " " << y << "\n";
        assert(x>=0 && x <= 4 * 1e7 && y >= 0 && y <= 4 * 1e7);
        
    }
    

}