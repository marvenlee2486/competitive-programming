#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;


//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define repn(i,a,b) for(int i=(a);i<=(b);i++)
#define repin(i,a,b,x) for(int i=(a);i<(b);i+=x)
#define repnin(i,a,b,x) for(int i=(a);i<=(b);i+=x)
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define fbo find_by_order
#define ook order_of_key
#define ALL(v) v.begin(),v.end()
#define FILL(arr,x) memset(arr,x,sizeof arr);

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 1e5+2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif




int main()
{
  string s;
    cin >> s;
    s ='X'+s;
    bool ans =0;
    int idx= -1;
    int length = 0;
    vector<int>len;
    for(int i=1;i<s.size();i++){
        if(s[i]=='0' && idx == -1) continue;
        idx = 0;
        if(s[i]!=s[i-1]){
            if(length!=0) len.push_back(length);
            length = 0;
            if(len.size()==2){
                bool temp = 0;
                if(len[1]%3==0 && len[0]%3==0) temp = 1;
                else if(len[1]%3==0) temp = 0;
                else if(len[0]%3==0) temp = 0;
                else temp = 1;
                if(temp) ans = !ans;
                
                
                length = len[0];
                len.clear();
            }
            
        }
        length++;
        
    }
    if(length!=0) len.push_back(length);
            if(len.size()==2){
                bool temp = 0;
                if(len[1]%3==0 && len[0]%3==0) temp = 1;
                else if(len[1]%3==0) temp = 0;
                else if(len[0]%3==0) temp = 0;
                else temp = 1;
                if(temp) ans = !ans;

                len.clear();
            }
            length = 0;
    
    if(ans ) cout << "Alice\n";
    else cout << "Bob\n";
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
