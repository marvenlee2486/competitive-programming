#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 * 4;
vector<int> prime;

void sieve(){
    bitset<MAXN> bs;

    bs.reset();
    prime.emplace_back(2);

    for(int i = 3; i < MAXN; i+=2 ){
        if(bs[i]) continue;
        prime.emplace_back(i);

        int j = 2 * i;
        while(j < MAXN){
            bs.set(j);
            j += i;
        }
    }
}
// {\displaystyle \varphi (n)=p_{1}^{k_{1}-1}(p_{1}{-}1)\,p_{2}^{k_{2}-1}(p_{2}{-}1)\cdots p_{r}^{k_{r}-1}(p_{r}{-}1).}
int main(){
    sieve();
    int n;
    while(cin >> n && n){
        int nn = n;
        long long sum = 1;
        long long cnt = 0;
        for(int p: prime){
            if(p > sqrt(n)) break;
            cnt = 0;
            while(n % p == 0){
                n /= p;
                cnt ++;
            }
            if(cnt != 0){
                sum *= pow(p,cnt - 1) * (p - 1);
            }
            
        }
        if(n != 1){
            sum *= n - 1;
        }
        cout << sum << "\n";
    }
}