#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    bool a[10][10];
    memset(a,0,sizeof a);

    while(n--){
        int d,l,r,c;
        cin >> d >> l>> r >> c;
        r--,c--;
        for(int i=0;i<l;i++){
            int fr,fc;
            if(d==0){
                fr = r;
                fc = c+ i;
            }else{
                fr = r+i;
                fc = c;
            }
            if(fr<0 || fc <0 || fr >=10 || fc >=10 || a[fr][fc]){
                cout << "N\n";
                return 0;
            }
            a[fr][fc ] =1;

        }
        
    }
    cout << "Y\n";
    return 0;
}