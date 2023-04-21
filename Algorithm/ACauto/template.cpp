#include<bits/stdc++.h>
using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

void build(){
    for(int i = 0; i < K; i++)
}

int main(){
    string dict[] = {
        "i",
        "in",
        "tin",
        "sting"
    };

    for(int i = 0; i < 4; i++){
        add_string(dict[i]);
    }  
    string query = "stink";
    int cnt = 0;
    cout << "TRIE\n";
    for(auto v: t){
        cout << cnt << " th Node - ";
        for(int k = 0; k < 26; k++) if(v.next[k] != -1) cout << (char)('a' + k)  << ":" << v.next[k] << " ";
        cout << "\n";
        cnt++;
    }
    
    int cur = 0;
    cout << cur << " ";
    for(char c : query){
        cur = go(cur,c);
        cout << cur << " ";
        if(t[cur].leaf) cout << "ANS";
    }
    
    // cout << "ACA\n";
    // for(auto v: t){
    //     cout << cnt << " th Node - ";
    //     for(int k = 0; k < 26; k++) cout << (char)('a' + k)  << ":" << v.go[k] << " ";
    //     cout << "\n";
    //     cnt++;
    // }

}