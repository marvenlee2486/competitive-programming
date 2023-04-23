#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

int dj[] = {0, 1, 1, 1};
int di[] = {1, 1, 0, -1};

void solve(){
    int n,k;
    cin >> n >> k;

    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];

    int xcnt = 0, ocnt = 0;
    set<ii> win;
    int side = -1;
    vector<ii> xx, yy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == 'x') {
                xx.emplace_back(i,j);
                xcnt++;
            }
            else if(s[i][j] == 'o') {
                yy.emplace_back(i,j);
                ocnt++;
            }
            else continue;
            
            for(int d = 0; d < 4; d++){
                bool can = true;
                for(int st = 1; st < k; st++){
                    int ni = i + di[d] * st, nj = j + dj[d] * st;

                    if(ni < 0 || ni >= n || nj < 0 || nj >= n || s[ni][nj] != s[i][j] ) {
                        can = false;
                        break;
                    }

                }
                if(can){
                    if( (side == 1 && s[i][j] == 'x') || (side == 0 && s[i][j] == 'o') ){
                        cout << "NIE\n";
                        return;
                    }
                    if( side == -1 ){
                        if(s[i][j] == 'x') side = 0;
                        else side = 1;

                        for(int st = 0; st < k; st++){
                            int ni = i + di[d] * st, nj = j + dj[d] * st;

                            win.emplace(ni, nj);
                        }  

                    }else{
                        set<ii> nw;
                        for(int st = 0; st < k; st++){
                            int ni = i + di[d] * st, nj = j + dj[d] * st;
                            if(win.find(ii(ni,nj)) != win.end()){
                                nw.emplace(ii(ni,nj));
                            }
                        }  
                        win = nw;
                    }
                }
            }
        }
    }
    if(side == -1){
        if( (n % 2 == 0 && xcnt != ocnt) || (n % 2 == 1 && abs(xcnt - ocnt) != 1) || xcnt + ocnt != n * n ) {
            cout << "NIE\n";
            return;
        }
        
    cout << "TAK\n";
        int turn = 0;
        if(ocnt > xcnt) turn = 1;
        while(xx.size() != 0 || yy.size() != 0){
            if(turn == 0){
                cout << xx.back().first + 1 << " " << xx.back().second + 1 << "\n";
                xx.pop_back();
            }
            else {
                cout << yy.back().first + 1 << " " << yy.back().second + 1 << "\n";
                yy.pop_back();
            }
            turn = 1 - turn;
        }
        return ;
    }

    if(win.size() == 0 || (side == 0 && (xcnt - ocnt < 0 || xcnt - ocnt > 1 )  ) || (side == 1 && (ocnt - xcnt < 0 || ocnt - xcnt > 1) ) ){
        cout << "NIE\n";
        return;
    }
    cout << "TAK\n";
    int xidx = 0, yidx = 0;
    
    int turn = 0;
    if(side == 0 && xcnt == ocnt || side == 1 && ocnt == xcnt + 1)  turn = 1;
    for(int k = 0; k < 2 * min(xcnt,ocnt); k++){
        if(turn == 0){
            if(side == 0){
                while(xidx != xcnt &&  win.find(xx[xidx]) != win.end() ) xidx++;
                if(xidx == xcnt){
                    cout << win.begin()->first + 1 << " " << win.begin()->second + 1 << "\n";
                    win.erase(win.begin());
                }else{
                    cout << xx[xidx].first + 1 << " " << xx[xidx].second + 1 << "\n";
                    xidx++;
                }
            }else{
                cout << xx[xidx].first + 1 << " " << xx[xidx].second + 1 << "\n";
                xidx++;
            } 
        }
        else{
            if(side == 1){
                while(yidx != ocnt &&  win.find(yy[yidx]) != win.end() ) yidx++;
                if(yidx == ocnt){
                    cout << win.begin()->first + 1 << " " << win.begin()->second + 1 << "\n";
                    win.erase(win.begin());
                }else{
                    cout << yy[yidx].first + 1 << " " << yy[yidx].second + 1 << "\n";
                    yidx++;
                }
            }else{
                cout << yy[yidx].first + 1 << " " << yy[yidx].second + 1 << "\n";
                yidx++;
            }
        }
        
        turn = 1 - turn;
    }  
    if(win.size() != 0){
        cout << win.begin()->first + 1<< " " << win.begin()->second + 1 << "\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}