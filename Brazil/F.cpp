#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int lg=0,rg=0,ls=0,rs=0;
    int server = 0;
    for(char c:s){
        if(c=='Q'){
            if(lg == 2){
                cout << lg << " (winner) - " << rg <<"\n";
                lg =0, rg=0;
                server =0;
                ls=0,rs=0;
            }
            else if(rg == 2){
                cout << lg << " - " << rg << " (winner)\n";
                lg =0, rg=0;
                server =0;
                ls=0,rs=0;
            }
            else{
                if(server==0){
                    printf("%d (%d*) - %d (%d)\n",lg,ls,rg,rs);
                }else{
                    printf("%d (%d) - %d (%d*)\n",lg,ls,rg,rs);
                }
            }
        }

        else if(c=='S'){
            if(server==0){
                ls++;
            }
            else{
                rs++;
            }
        }
        else{
            if(server==0){
                rs++;
            }
            else {
                ls++;
            }
            server = 1 - server;
        }

        if((max(ls,rs)>=5 && abs(ls-rs)>=2 ) || max(ls,rs)==10){
            if( ls>rs){
                lg++;
            }
            else{
                rg++;
            }
            ls = 0,rs= 0;
        }

    }
    return 0;
}