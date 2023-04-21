#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Can return the vector d
ll manacher(string _s){
    // Add # in between all the characters to generalize even and odd length palindrome
    string s = "#";
    for(char c : _s) s += c, s += '#';
    int n = s.size();
    vector<int> d(n);
    // A little trick to ensure linearity 
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r)? 1 : min(d[l + r - i], r - i + 1);
        while(0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        d[i] = k--;
        if(i + k > r) l = i - k, r = i + k;  
    }
    // Calculate the number of palindrome
    ll ret = 0;
    for(int c : d) ret += c/2;
    return ret;
}

int main(){
    string s;
    cin >> s;
    cout << manacher(s) << "\n";
}