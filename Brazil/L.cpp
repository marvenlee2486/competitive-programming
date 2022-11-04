#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int di[] = {1,1,-1,0};
int dj[] = {0,1,1,1};
int main(){
    int l,c;
    cin >> l >> c;
    string a[l];
    set<int> cnt[l][c];
   
    for(int i=0;i<l;i++) cin >> a[i];

    int n;
    cin >> n;
    int idx =0;
    while(n--){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        int len = s.size();
        for(int i=0;i<l;i++){
            for(int j=0;j<c;j++){
                // horizontal
                for(int dir = 0; dir<4; dir++){
                    string ss ="";
                    for(int d = 0; d<len;d++){
                        int ni = i + di[dir]*d,nj = j + dj[dir]*d;
                        if(ni<0|| nj <0 || ni >=l || nj >=c) break;
                        ss += a[ni][nj];
                    }
                    sort(ss.begin(),ss.end());
                    if(ss == s){
                        for(int d = 0; d<len;d++){
                            int ni = i + di[dir]*d,nj = j + dj[dir]*d;
                            cnt[ni][nj].insert(idx);
                        }
                    }
                }
                
            }
        }
        idx++;
    }
    int ans=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(cnt[i][j].size()>=2) ans++;
        }
    }
    cout << ans;
    return 0;
}