#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> prime;
int maxn = 400001;
const ll INF = 1e9;
void sieve(){
    int n = maxn;
    int is[n];
    memset(is, 0, sizeof is);

    prime.emplace_back(2);
    for(int i = 2; i < n; i+=2){
        is[i] = 1;
    }

    for(int i = 3; i < n; i+=2){
        if(is[i]) continue;
        prime.emplace_back(i);
        int j = i * 2;
        while(j < n){
            is[j] = 1;
            j += i;
        }
    }
}

bool isprime(ll n){
    for(ll p : prime){
        if( p > sqrt(n)) return true;
        if(n % p == 0) return false;
    }
    return true;
}
int main(){
    sieve();
    //cout << prime.size() << "\n";
    ll n;
    while(cin >> n && n){
        for(ll i = 2 * n + 1; i <= INF * INF; i+=2){
            if(isprime(i))  {
                cout << i;
                break;
            }
        }
        if(isprime(n)){
        cout << "\n";
        }
        else{
            cout << " (" << n << " is not prime)\n";
        }
    }
    
}