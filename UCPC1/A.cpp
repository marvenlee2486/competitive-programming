#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for(auto& i: a) cin >> i;
    for(auto& i: b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = -1;
    vector<int> p(m, 0);
    for(int i = 0; i < m; i++){
        if(i == 0) p[i] = b[i];
        else p[i] = p[i - 1] + b[i];
    }


    long long sum = 0;
    for(int i = 0; i < n; i++){
        // cout << j << " ";
        while(j < m - 1 && b[j + 1] < a[i] ) j++;
        if(j != -1) sum += (j + 1) * a[i] - p[j]  +  (p[m - 1] - p[j]) - (m - (j + 1)) * a[i];
        else sum += p[m - 1] - m * a[i];
    }
    long double ans = sum * 1.0 /(n * m);
    cout << ans << "\n";
    // cout << sum << "\n";

}