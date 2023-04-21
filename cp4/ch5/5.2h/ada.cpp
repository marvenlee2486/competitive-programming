#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a;
    vector<int> na (n , 0);
    for(auto& i: na) cin >> i;
    a.emplace_back(na);

    bool gg = true;
    do{
        na.clear();
        for(int i = 1; i < a.back().size(); i++) na.emplace_back(a.back()[i] - a.back()[i-1]);
        gg = false;
        for(int i = 1; i < na.size(); i++) if(na[i] != na[i-1]) gg = true;
        a.emplace_back(na);
        
    }while(gg);

    for(int i = a.size() - 2; i >= 0; i--){
        a[i].emplace_back(a[i+1].back() + a[i].back());
    }
    cout << a.size() - 1 << " " << a[0].back() << "\n";


}