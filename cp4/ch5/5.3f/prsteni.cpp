#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<unsigned int> a(n, 0);
    for(auto &i: a) cin >> i;

    for(int i = 1; i < n; i++){
        int g = __gcd(a[0], a[i]);

        cout << a[0]/g << "/" << a[i]/g << "\n";
    }
}