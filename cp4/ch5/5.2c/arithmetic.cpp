#include<bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<char, string> mp1;
unordered_map<string, char> mp2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    mp1['0'] = "000";
    mp1['1'] = "001";
    mp1['2'] = "010";
    mp1['3'] = "011";
    mp1['4'] = "100";
    mp1['5'] = "101";
    mp1['6'] = "110";
    mp1['7'] = "111";

    mp2["0000"] = '0';
    mp2["0001"] = '1';
    mp2["0010"] = '2';
    mp2["0011"] = '3';
    mp2["0100"] = '4';
    mp2["0101"] = '5';
    mp2["0110"] = '6';
    mp2["0111"] = '7';
    mp2["1000"] = '8';
    mp2["1001"] = '9';
    mp2["1010"] = 'A';
    mp2["1011"] = 'B';
    mp2["1100"] = 'C';
    mp2["1101"] = 'D';
    mp2["1110"] = 'E';
    mp2["1111"] = 'F';


    string s;
    cin >> s;
    string bin = "";

    for(char c:s){
        bin += mp1[c];
    }
    string ans = "";
    while(bin[0] == '0') bin = bin.substr(1,bin.size()-1);
    while(bin.size() % 4 != 0 || bin.size() == 0){
        bin = "0" + bin;
    }

    for(int i = 0; i < bin.size(); i+=4){
        ans += mp2[bin.substr(i,4)];
    }
    cout << ans << '\n';
}