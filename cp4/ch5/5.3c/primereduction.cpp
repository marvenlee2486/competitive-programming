#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 * 4;

vector<int> prime;
void sieve(){
    bitset<MAXN> bs;
    bs.reset();

    prime.emplace_back(2);

    for(int i = 4; i < MAXN; i+=2) bs.set(i);

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
    int cnt = 0;
    while(cin >> n && n != 4){
        cnt = 0;
        while(true){
            int sum = 0;
            for(int p : prime){
                if(p > sqrt(n)) break;
                
                while(n % p == 0){
                    sum += p;
                    n /= p;
                }
            }
            if(n != 1) sum += n;
            cnt++;
            if(sum == n){
                cout << n << " " << cnt << "\n";
                break;
            }
            n = sum;
        }
    }
}