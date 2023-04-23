#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve(){
    string s;
    getline(cin,s);
    
    string ope = "+-*/%";
    char last = '+';
    bool error = false;
    int cnt = 0;

    bool cannot = true;

    for(char c: s){
        //cout << c << " ";
        if(c ==' ') continue;
        else if(c == '('){
            if( ope.find(last) == string::npos && last != '('){
                error = true;
                break;
            }
            cnt ++;
            cannot = true;
        }
        else if(c == ')'){
            if ( ope.find(last) != string::npos || last == '(' ){
                error = true;
                break;
            }
            cnt --;
            if(cnt<0){
                error = true;
                break;
            }
            cannot = false;
        }
        else if(ope.find(c)!= string::npos){
            if(cannot){
                error = true;
                break;
            }

            cannot = true;
        }
        else {
            if(!cannot){
                error = true;
                break;
            }
            cannot = false;
        }
        last = c;
    }   
    if(cnt !=0 ||  ope.find(last)!=string::npos) error = true;
    if(error) {
        cout << "error\n";
        return;
    }


    stack<int> st;
    st.push(1);
    bool wrong = false;
    for(char c :s){
        if(c==' ') continue;
        if(c=='(') st.push(1);
        else if(c==')'){
            if(st.top() !=4){
                wrong = true;
                break;
            }
            st.pop();
            if(st.top()!= 1 && st.top() !=3){
                wrong = true;
                break;
            }
            int in = st.top();
            st.pop();
            st.push(in+1);
        }
        else if( ope.find(c) != string::npos ){
            if(st.top() !=2){
                wrong = true;
                break;
            }
            st.pop();
            st.push(3);
        }else{
            if(st.top()!= 1 && st.top() !=3){
                wrong = true;
                break;
            }
            int in = st.top();
            st.pop();
            st.push(in+1);
        }
    }
    if(st.size() != 1 || st.top() != 4) wrong = true;
    if(wrong) cout << "improper\n";
    else cout << "proper\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  
  while(t--) solve();
  return 0;
}

