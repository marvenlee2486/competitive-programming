#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector< vector<int> > a(n , vector<int>(n, 0));
    vector< vector<int> > cut(n , vector<int>(n, 0));
    vector< vector<int> > cnt(n , vector<int>(n, 0));
    vector< vector<int> > op(3 , vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j <= i; j++){
            a[i][j] = s[j] - '0';
        }
    }
    // 0 - i
    // 1 - j
    // 2 - i - j
    queue<ii> q;
    auto op1 = [&](int i, int on){
        if(op[0][i] != 0) return;
        op[0][i] = 1 + on;
        for(int j = 0; j <= i; j++){
            cut[i][j] += on;
            cnt[i][j] += 1;
            if(cnt[i][j] == 2) q.emplace(i, j);
        }
    };
    
    auto op2 = [&](int j, int on){
        if(op[1][j] != 0) return;
        op[1][j] = 1 + on;
        for(int i = n - 1; i >= j; i--){
            cut[i][j] += on;
            cnt[i][j] += 1;
            if(cnt[i][j] == 2) q.emplace(i, j);
        }
    };

    auto op3 = [&](int ij, int on){
        if(op[2][ij] != 0) return;
        op[2][ij] = 1 + on;
        // i - j = ij
        for(int i = n - 1, j = i - ij; j >= 0; j--, i--){
            cut[i][j] += on;
            cnt[i][j] += 1;
            if(cnt[i][j] == 2) q.emplace(i, j);
        }
    };

    if(n <= 3){
        cout << "Yes\n";
        return 0;
    }
    op1(n - 1, 1);
    op1(n - 2, 1);
    op2(0, 1);

    while(!q.empty()){
        auto[i,j] = q.front();
        q.pop();
        int on = 
        ((cut[i][j] == 2 || cut[i][j] == 0) && a[i][j] == 1) ||
        (cut[i][j] == 1 && a[i][j] == 0);
        
        op1(i,on);
        op2(j,on);
        op3(i - j, on);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            // cout << cut[i][j] << " ";
            if((cut[i][j] % 2) !=  a[i][j] ){
                cout << "No\n";
                return 0;
            }
        }
        // cout << "\n";
    }
    cout << "Yes\n";
    
    return 0;
}