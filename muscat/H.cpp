#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
void solve(){
    int n;
    cin >> n;
    vector<int> chosen(2 * n, 0);
    unordered_map<ll, vector<ii>> xmap, ymap;
    unordered_set<ll> xchosen, ychosen;
    vector<ii> el;
    for(int i = 0; i < 2 * n; i++){
        int x,y;
        cin >> x >> y;
        xmap[x].emplace_back(y,i);
        ymap[y].emplace_back(x,i);
        el.emplace_back(x,y);
    }
    vector<ii> ans;
    for(int i = 0; i < 2 * n; i++){
        if(chosen[i]) continue;

        queue<int> intersection, alone;
        vector<int> points;
        points.emplace_back(i);
        queue<ii> process;
        process.emplace(el[i].first, 0);
        process.emplace(el[i].second, 1);

        while(!process.empty()){
            auto[val, para] = process.front();
            process.pop();
            if(para == 0){
                if(xchosen.find(val) != xchosen.end()) continue;
                xchosen.emplace(val);

                for(auto[y,idx]: xmap[val]){
                    process.emplace(y, 1);
                    points.emplace_back(idx);
                }

            }
            else if(para == 1){
                if(ychosen.find(val) != ychosen.end()) continue;
                ychosen.emplace(val);

                for(auto[x,idx]: ymap[val]){
                    process.emplace(x, 0);
                    points.emplace_back(idx);
                }
            }
        }

        unordered_map<int, int> alonex, aloney;
        unordered_map<int, vector<ii> >intersectionx; // intersectiony;
        vector<int> unprocess;
        for(int idx: points){
            if(xmap[el[idx].first].size() == 1){
                if(aloney.find(el[idx].second) != aloney.end()){
                    ans.emplace_back(aloney[el[idx].second], idx);
                    aloney.erase(el[idx].second);
                }
                else{
                    aloney[el[idx].second] = idx;
                }
            }
            else if(ymap[el[idx].second].size() == 1){
                if(alonex.find(el[idx].first) != alonex.end()){
                    ans.emplace_back(alonex[el[idx].first], idx);
                    alonex.erase(el[idx].first);
                }
                else{
                    alonex[el[idx].first] = idx;
                }
            }
            else{
                intersectionx[el[idx].first].emplace_back(el[idx].second, idx);
            }
        }
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}