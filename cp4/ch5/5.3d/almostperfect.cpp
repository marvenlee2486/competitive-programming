#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4 * 1e4;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    while(cin >> n){
        int sum = 1;
        for(int i = 2; i <= sqrt(n); i++){
            if( n % i == 0) {
                sum += i;
                if(i != n/i) sum += n/i;
            }
        }
        cout << n << " ";
        if(sum == n) cout << "perfect\n";
        else if(abs(sum - n) <= 2) cout << "almost perfect\n";
        else cout << "not perfect\n";
    }
}