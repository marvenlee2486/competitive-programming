#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
struct trie{
    trie* nxt[2];
    trie(){nxt[0] = NULL, nxt[1] = NULL;};
};
string convert(int x){
    string ret = "";
    for(int i = 0; i < 32; i++){
        ret += '0' + x % 2;
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void insert(trie* root, int x){
    trie* cur = root;
    string ret = convert(x);
    for(char c: ret){  
        if(cur->nxt[c - '0'] == NULL) cur->nxt[c - '0'] = new trie();
        cur = cur->nxt[c - '0'];
    }
}

int greatest(trie* root, int x){
    trie* cur = root;
    string ret = convert(x);
    int res = 0;
    // cout << x << " " << ret << "\n";
    for(char c: ret){
        res *= 2;
        if(cur->nxt[1 - c + '0']){
            res += 1;
            cur = cur->nxt[1 - c + '0'];
        }
        else{
            cur = cur->nxt[c - '0'];
        }
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    vector<ii> as;
    vector<int> prefix(n + 1, 0);
    trie* t[n + 1];
    vector<int> ans(n + 1, 0);
    vector<int> nl(n + 2, 1);
    vector<int> nr(n + 2, n);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        as.emplace_back(a[i], i);
        prefix[i] = prefix[i - 1] ^ a[i];
        t[i] = new trie();
        // cout << i << " " << t[i] << "\n";
        //insert(t[i],0);
        insert(t[i],prefix[i]);

        nl[i] = i;
        nr[i] = i;
    }

    stack<ii> mono;
    vector<int> l(n + 1, 1);
    vector<int> r(n + 1, n);
    for(int i = 1; i <= n; i++){
        while(!mono.empty() && mono.top().first < a[i]){
            r[mono.top().second] = i - 1;
            mono.pop();
        }
        mono.emplace(a[i], i);
    }
    while(!mono.empty()) {
        //r[mono.top().second] = mono.top().second;
        mono.pop();
    }
    for(int i = n; i >= 1; i--){
        while(!mono.empty() && mono.top().first < a[i]){
            l[mono.top().second] = i + 1;
            mono.pop();
        }
        mono.emplace(a[i],i);
    }
    while(!mono.empty()) {
        //l[mono.top().second] = mono.top().second;
        mono.pop();
    }
    
    sort(as.begin(), as.end());
    int res = 0;
    for(auto&[_,idx]: as){
        cout << "idx : " <<  idx << "\n";
        // assume t[idx] already contains everythings.
        int left = l[idx], right = r[idx];
        cout << left << " " << right << '\n';
        nl[right + 1] = idx;
        nr[left - 1] = idx;
        if(left == right){
            continue;
        }
        cout << "NOT leaf\n";
        

        trie* small = t[nl[idx]];
        trie* big = t[nr[idx]];
        cout << nl[idx] << " " << nr[idx] << "\n";
        cout << small << " " << big << "\n";
        right = idx;
        int buf = 0;
        if(right - idx < idx - left) {
            cout << "SMALL is right so take " << nl[idx] << "\n";
            swap(small,big);
            right = r[idx];
            left = idx;
            buf=  1;
        }
        // Find greatest.
        int maxv = max(ans[nl[idx]], ans[nr[idx]]);
        cout << maxv << "\n";
        cout << big << "\n";
        cout << greatest(big, 0) << "\n";

        if(buf == 1)
            for(int i = left; i <= right; i++){
                cout << i << ": " << greatest(big, prefix[i] ^ a[idx]) << "\n";
                maxv = max(maxv, greatest(big, prefix[i] ^ a[idx]));
            }

        // Merge.
        for(int i = left; i <= right; i++){
            // cout << "INSERTED\n";
            insert(big, prefix[i]);
        }
        t[idx] = big;
        ans[idx] = maxv;
        res = max(maxv, res);
    }
    cout << res << "\n";
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}