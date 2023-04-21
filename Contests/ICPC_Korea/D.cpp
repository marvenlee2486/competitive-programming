#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
map<char,string> mpp;
void solve(){
    string s;
    cin >> s;
    
    if(s.substr(s.size()-2,2) == "ne"){
        cout << s.substr(0,s.size()-2) << "anes" << "\n";
        return;
    }
    if(mpp.find(s[s.size()-1]) == mpp.end()){
        cout << s <<"us\n";
        return;
    }
    cout << s.substr(0,s.size()-1) << mpp[s[s.size()-1]] << "\n";
    

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  cin >> t;
  mpp['a'] = "as";
    mpp['i'] = "ios";
    mpp['y'] = "ios";
    mpp['l'] = "les";
    mpp['n'] = "anes";
    mpp['o'] = "os";
    mpp['r'] = "res";
    mpp['t'] = "tas";
    mpp['u'] = "us";
    mpp['v'] = "ves";
    mpp['w'] = "was";
  while(t--) solve();
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
