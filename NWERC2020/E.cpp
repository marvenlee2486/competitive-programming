#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
set<ii> valid_move;
vector<ii> moved;
int n;

bool can_eat(int ax, int ay, int bx, int by){
    // a eat b
    if(ax == bx && ay == by) return true;
    for(auto&[x1,y1]:moved){
        int nx = ax + x1;
        int ny = ay + y1;

        if( nx<1 || nx >n || ny<1 || ny>n) continue;

        int rx = bx - nx ;
        int ry = by - ny ;

        if(valid_move.find(ii(rx,ry)) == valid_move.end()) continue;
        
        return true;
    }
    return false;

}

int main(){ 

    cin >> n;
    int ax,bx,ay,by;
    cin >> ax >> ay >> bx >> by;
    int x,y;
    

    for(int i=0;i<n;i++){
        cin >> x >> y;
        moved.emplace_back(x,y);
        valid_move.insert(ii(x,y));
    }
    if(can_eat(ax,ay,bx,by))
        cout << "Alice wins\n";
    else if(n<=100){
        int a[n+1][n+1];
        memset(a,0,sizeof a);
        a[bx][by]=1;
        for(int i=0;i<n;i++){
            int nx = bx + moved[i].first;
            int ny = by + moved[i].second;

            if( nx<1 || nx >n || ny<1 || ny>n) continue;

            a[nx][ny] = 1;


            for(int j=0;j<n;j++){
                int nnx =  nx + moved[j].first;
                int nny = ny + moved[j].second;
                if( nnx<1 || nnx >n || nny<1 || nny>n) continue;
                a[nnx][nny] = 1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==0){
                    cout << "tie "<< i << " " << j << "\n";
                    return 0;
                }
            }
        }
        cout << "Bob wins\n";
        return 0;
    }
    else{
        x = rng()%n +1 ;
        y = rng()%n +1;

        while(can_eat(bx,by,x,y)){
            x = rng()%n +1 ;
            y = rng()%n +1;
        }
        cout << "tie " << x << " " << y << '\n';
    }


}