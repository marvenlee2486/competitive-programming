#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

void solve(){
    int n;
    cin >> n;
    vector< pair<int,ii> > st;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int req = 0;
        int cur = 0;
        for(char c: s){
            if(c == '('){
                cur++;
            }
            else {
                cur--;
                req = min(req,cur);
            }
        }
        st.push_back( pair<int,ii>(req * -1, ii(cur,i) ) );
    }

    sort(st.begin(),st.end());
    
    int cur = 0;
    if(st[0].first >0){
        cout << "impossible\n";
        return;
    }
    priority_queue< pair<int,ii> > q;
    q.push(pair<int,ii>(st[0].second.first, ii(st[0].first,st[0].second.second)));
    vector<int>ans;
    int idx = 1;
    while(!q.empty()){
        if(cur < q.top().second.first){
            cout << "impossible\n";
            return;
        }
        cur += q.top().first;
        if(cur <0){
            cout << "impossible\n";
            return;
        }
        ans.push_back(q.top().second.second);
        q.pop();
        
        while(idx<n){
            //cout << cur << " " << idx << " " << st[idx].first << "\n";
            if(st[idx].first > cur) break;
            q.push(pair<int,ii>(st[idx].second.first, ii(st[idx].first,st[idx].second.second)));
            idx++;
        }
    }
    if(ans.size() !=n || cur !=0) {
        cout << "impossible\n";
        return;
    }
    for(int c:ans){
        cout << c+1 << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}