#include<bits/stdc++.h>
using namespace std;


namespace AC {

const int N = 1e6;
int tr[N][26], tot; // next, total
int e[N], fail[N]; // occurence in dict (can change to store the dict if need to print), suffix link
int p[N]; // Parent
char pch[N];

int dp[N];
// Trie
void insert(string s) {
  int u = 0;
  for (int i = 0; i < s.size(); i++) {
    if (!tr[u][s[i] - 'a']) 
        tr[u][s[i] - 'a'] = ++tot, p[tot] = u;  // 如果没有则插入新节点
    u = tr[u][s[i] - 'a'];                      // 搜索下一个节点
  }
  e[u]++;                                       // 尾为节点 u 的串的个数
}

queue<int> q;
// To be called after insert
void build() {
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < 26; i++) {
      if (tr[u][i]) {
        fail[tr[u][i]] = tr[fail[u]][i];  // fail数组：同一字符可以匹配的其他位置
        q.push(tr[u][i]);
      } 
      else tr[u][i] = tr[fail[u]][i];
    }
  }

  for(int i = 0; i <= tot; i++) dp[i] = -1;
}

// Total Number of Occurences, If want one occurence, can set dp[u] = val as visited. return 0;
int dfs(int u){
    if(dp[u] != -1) return dp[u];
    if(u == 0) return dp[u] = 0;
    return dp[u] = dfs(fail[u]) + e[u];
}

int query(string t) {
  int u = 0, res = 0;
  for (int i = 0; i < t.size(); i++) {
    u = tr[u][t[i] - 'a'];  // 转移
    res += dfs(u);
  }
  cout << res << "\n";
  return res;
}
}  // namespace AC


int main(){
    string dict[] = {
        "i",
        "in",
        "tin",
        "sting"
    };
    
    for(int i = 0; i < 4; i++){
        AC::insert(dict[i]);
    }  
    AC::build();
    string query = "stingin";
    
    cout << "TRIE\n";
    for(int i = 0; i <= AC::tot; i++){
        cout << i << " th Node - ";
        for(int k = 0; k < 26; k++) if(AC::tr[i][k] != 0) cout << (char)('a' + k)  << ":" << AC::tr[i][k] << " ";
        cout << "Suffix: " << AC::fail[i];
        cout << "\n";
    }
    AC::query(query);

}