#include<bits/stdc++.h>
using namespace std;

int dir(string A, string B){
    if(A.size() > B.size()) return 1;
    else if(A.size() < B.size()) return -1;

    for(int i = 0; i < A.size(); i++){
        if(A[i] > B[i]) return 1;
        else if(A[i] < B[i]) return -1;
    }
    return 0;
}

string minus(string A, string B){
    if(dir(A,B) == -1) return "0";

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    while(B.size() != A.size()) B += '0';
    string res = "";
    for(int i = 0; i < A.size(); i++){
        if(A[i] < B[i]){
            int j = i + 1;
            while(A[j] == '0'){
                A[j] = '9';
                j++;
            }
            A[j]--;

            res = A[i] + 10 - B[i] + '0';
        }
        else{
            res = A[i] - B[i] + '0';
        }
    }
}

void solve(){
    string n;
    cin >> n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}