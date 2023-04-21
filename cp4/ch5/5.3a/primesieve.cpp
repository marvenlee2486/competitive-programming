#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e8+1;
bitset<maxn> is;
int sieve(int n){
    is.set();
    is[0] = is[1] = 0;
    int cnt = 1;
    for(int i = 4; i <= n; i+= 2){
        is[i] = 0;
    }
    for(int i = 3; i <= n; i+= 2){
        if(!is[i]) continue;
        cnt ++;
        int j = i * 2;
        while(j <= n){
            is[j] = 0;
            j += i;
        }
    }
    if(n == 1) cnt = 0;
    return cnt;
}

int main(){
    int n,q;
    cin >> n >> q;
    cout << sieve(n) << "\n";
    while(q--){
        int x;
        cin >> x;
        if(is[x]) cout << "1\n";
        else cout << "0\n";
    }
}