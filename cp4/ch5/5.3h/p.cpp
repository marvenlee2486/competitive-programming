#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1002;
vector<int> prime;

void sieve(){
    prime.emplace_back(2);
    bitset<MAXN> bs;
    bs.reset();

    for(int i = 3; i < MAXN; i+=2){
        if(bs[i]) continue;
        prime.emplace_back(i);
        int j = 2 * i;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    sieve();
    int n;
    cin >> n;
    
    for(int p : prime){
        if(p > sqrt(n)) break;
        int cnt = 0;
        while(n % p == 0){
            n /= p;
            cnt++;
        }
        if(cnt != 0) cout << p << "^" << cnt  << " ";
    }

}