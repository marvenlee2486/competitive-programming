#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
void solve() {
  ll n,m;
  cin >> n >> m;
  vector<ii> a(n);
  vector<vector<int> > graph(n+1, vector<int>());
  for(int i=0;i<n;i++) {
    int x;cin >> x;
    a[i] = ii(x,i);
  }
  stack<vector<ii>> st;
  st.push(vector<ii>(1,a[0]));
  for(int i = 1; i < n; i++){
    vector<ii> pos = st.top();
    while(!st.empty() && a[i].first > st.top().back().first){
        if(pos.back().second != st.top().back().second){
            for(auto&[x,v]:pos){
                graph[st.top().back().second].push_back(v);
            }

            //graph[st.top().second].push_back(pos);
            //pos = st.top().second;
        }
        pos = st.top();
        st.pop();
    }

    if(!st.empty() && st.top().back().first == a[i].first){
        st.top().push_back(a[i]);
    }
    else{
        st.push(vector<ii>(1,a[i]));
    }

  }
  
  vector<ii> pos = st.top();
  while(!st.empty()){
        if(pos.back().second != st.top().back().second){
            for(auto&[x,v]:pos){
                graph[st.top().back().second].push_back(v);
            }

            //graph[st.top().second].push_back(pos);
            //pos = st.top().second;
        }
        pos = st.top();
        st.pop();
    }

 
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
 
  
    solve();
  
}