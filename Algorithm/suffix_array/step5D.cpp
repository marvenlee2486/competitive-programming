#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> ii;


vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s;
    cin >> s;
    
    vector<int> arr = prefix_function(s);
    ll ans = 0;
    for(int i = 0; i < arr.size(); i++){
        ans += arr[i] + 1;
    }
    cout << ans << "\n";
    
}