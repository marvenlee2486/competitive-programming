#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    bitset<1000002> bs;
    bs.reset();
    int cnt = 0;
    for(int i = 2; i <= n; i+=2){
        bs.set(i);
        cnt++;
        if(cnt == k){
            cout << i << "\n";
            return 0;
        }
    }

    for(int i = 3; i <= n; i+=2){
        if(bs[i]) continue;

        int j = i;
        while(j<=n){
            if(!bs[j]) cnt++;
            bs.set(j);
            if(cnt == k){
                cout << j << "\n";
                return 0;
            }
            j+= i;
        }
    }
}