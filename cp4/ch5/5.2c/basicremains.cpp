#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool geq(string l, string r){
    while(l.size() != 0 && l[0] == '0') l = l.substr(1,l.size()-1);
    while(r.size() != 0 && r[0] == '0') r = r.substr(1,r.size()-1);
    if(l.size() < r.size()) return false;
    else if(l.size() > r.size()) return true;

    for(int i = 0; i < l.size(); i++){
        if(l[i] < r[i]) return false;
        else if(l[i] > r[i]) return true;
    }
    return true;
}

int b;

string add(string l, string r){
    if(geq(l,r)) swap(l,r);
    // cout << l << " ADD " << r << " = " ;
    // l is less than r
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    string ans = "";
    int remain = 0;
    for(int i = 0; i < r.size(); i++){
        remain =  ( (i < l.size())? l[i] - '0': 0 ) + r[i] - '0' + remain;
        ans += (char)('0' + remain % b);
        remain /= b;
    }
    while(remain != 0){
        ans += (char)('0' + remain % b);
        remain /= b;
    }
    reverse(ans.begin(), ans.end());
    // cout << ans << "\n";
    return ans;
}

string subtract(string l, string r){
    // cout << l << " SUB " << r << " = " ;
    assert(geq(l,r));
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    string ans = "";
    
    for(int i = 0; i < l.size(); i++){
        if(i >= r.size()){
            ans += l[i];
            continue;
        }
        if(l[i] < r[i]){
            for(int j = i + 1; j < l.size(); j++){
                if(l[j] == '0') l[j] = '0' + b - 1;
                else {
                    l[j]--;
                    break;
                }
            }
            l[i] += b;
        }
        ans += (char)('0' + l[i] - r[i]);
    }
    reverse(ans.begin(), ans.end());
    // cout << ans <<"\n";
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string p,q;
    while(cin >> b && b){
        cin >> p >> q;
        int st = 0;
        string sub = q;
        for(int i = 0; i < p.size(); i++){

            while(st < i && p[st] == '0') st++;
            string temp = p.substr(st,i - st + 1);
        
            string temp2 = q;
            if(!geq(temp,q)) continue;
            do{
                //cout << temp << " " << temp2 << "\n";
                sub = temp2;
                temp2 = add(sub,q);
            }while(geq(temp,temp2));

            string ans = subtract(temp,sub);
            for(int j = st; j <= i; j++){
                p[j] = ans[j - st];
            }
            // cout << st << " " << i << " " << p << "\n";
        }
        while(st < p.size() && p[st] == '0') st++;
        for(int j = st; j < p.size(); j++) cout << p[j];
        if(st == p.size()) cout << "0";
        cout << "\n";
    }
}