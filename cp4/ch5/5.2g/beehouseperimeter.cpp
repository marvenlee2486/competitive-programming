#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int dr[] = {0, 0, -1, -1, 1, 1};
int dc[] = {1, -1, 0, -1, 0, 1};

int main(){
    int r,k;
    cin >> r >> k; 

    bool a[2 * r + 1][2 * r + 1];
    bool visited[2 * r + 1][ 2 * r + 1];
    memset(a, 0 ,sizeof a);
    int ans = 0;
    int rowcnt[2 * r];
    for(int i = 1; i <= r; i++) rowcnt[i] = r + i - 1;
    for(int i = r; i <= 2 * r; i++) rowcnt[i] = 2 * r - 1 - (i - r); 
    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        int row = 1;
        int add = 0;
        while( c - rowcnt[row] > 0 ){
            c -= rowcnt[row];
            row++;
            if( row > r) add ++;
        }
        a[row][c + add] = true;  
    }

    queue<ii> q;
    int rv = r;
    memset(visited, 0, sizeof visited);
    q.emplace(0, 0);
    while(!q.empty()){
        int r, c;
        tie(r,c) = q.front();
        q.pop();
        if(visited[r][c]) continue;
        visited[r][c] = 1;
        for(int d = 0; d < 6; d++){
            int nr = r + dr[d], nc = c + dc[d];
            //cout << nr << " " << nc << '\n';
            if(nr < 0 || nr > 2 * rv || nc < 0 || nc > 2 * rv || visited[nr][nc]) continue;
            //cout << "JERE\n";
            if(a[nr][nc]){
                ans += 1;
                continue;
            }
            //cout << "HERE\n";
            q.emplace(nr, nc);
        }
    }
    cout << ans << '\n';

}