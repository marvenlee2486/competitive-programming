#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    map<char, int> cnt;
    for (auto e: t)cnt[e]++;
    for (auto e: s) cnt[e]--;
    set<char> ans;
    for (auto [u, v]: cnt) if (v != 0) ans.emplace(u);
    for (auto e: ans) cout << e;
    cout << endl;
}