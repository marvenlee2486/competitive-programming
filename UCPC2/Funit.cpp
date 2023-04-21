#include<bits/stdc++.h>
using namespace std;
string add(string s1, string s2){
    if(s1.size() > s2.size()) swap(s1,s2);
    // reverse(s1.begin(),s1.end());
    // reverse(s2.begin(),s2.end());

    int c = 0;
    string ret = "";
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while(i >= 0 && j >= 0){
        int val = s1[i] + s2[j] - 2 * '0' + c;
        ret += '0' + val % 10;
        c = val / 10;
        i--;
        j--;
    }
    while(j >= 0){
        int val = s2[j] - '0' + c;
        ret += '0' + val % 10;
        c = val/10;
        j--;
    }
    while(c != 0){
        ret += '0' + c;
        c /= 10;
    }
    // for(int i = 0; i < s1.size(); i++){
    //     int val = s1[i] + s2[i] - 2 * '0' + c;
    //     ret += '0' + val % 10;
    //     c = val/10;
    // }
    // for(int i = s1.size(); i < s2.size(); i++){
    //     int val = s2[i] - '0' + c;
    //     ret += '0' + val % 10;
    //     c = val/10;
    // }
    reverse(ret.begin(),ret.end());
    return ret;
}

void min(string& s1, string s2){
    if(s1.size() < s2.size()) return;
    else if(s1.size() > s2.size()) {
        s1 = s2;
        return;
    }

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] < s2[i]) return;
        if(s1[i] > s2[i]) {
            s1 = s2;
            return;
        }
    }
}


int main(){
    string s1 = "1011";
    string s2 = "1002";
    min(s1,s2);
    cout << s1 << "\n";
}