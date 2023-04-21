#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll BIT = 26;
char CHAR1 = 'a';
int id_assign = 0;
struct trie{
  trie* next[BIT];
  int id = 0;
  int size[BIT]; // size of the subtree
  int depth;    // depth of the trie
  trie(int d):depth(d){
    memset(size,0,sizeof size);
    for(int i=0;i<BIT;i++) next[i]=NULL;
    id = id_assign ++;
  }
};
 
// Fixed Template
void insert(string s, trie* t){
  for(int i=0;i<s.size();i++){
    int c = s[i] - CHAR1;
    if( t->next[c] == NULL){
      t->next[c] = new trie(t->depth + 1);
    }
    t->size[c]++;
    t = t->next[c];
  }
}
 
// Depends see how you want to go throught the trie
ll query(string s, trie* t){
  ll ans = 0;
  // Go through the trie
  for(int i=0;i<s.size();i++){
    int c = s[i]-CHAR1;

    if(t->next[c] == NULL) {
      return 0;
    }
    
    t = t->next[c];  
  }
  return 1;
}
 
// For convert number into string of binary numbers
string convert(ll x){
  string s = "";
  for(int i=0; i<32; i++){
   char c = '0' + x%2;
   x/=2;
  s+=c;
 }
 reverse(s.begin(),s.end());
 return s;
}

void debug(trie* t){
    queue<trie*> q;
    q.push(t);
    while(!q.empty()){
        trie* tr = q.front();
        q.pop();
        cout << "Node " << tr->id << ": \n";
        int leaf = 0;
        for(int i = 0; i <BIT; i++){
            if(tr->next[i] == NULL) continue; //cout << "NULL";
            char c = CHAR1 + i;
            cout << "\t '"<< c << "' :";
            cout << tr->next[i]->id ;
            q.push(tr->next[i]);
            cout << "\n";
            leaf++;
        }
        if(leaf==0) cout << "Leaf Node\n";
        cout << "\n";
    }
}


int main(){
    trie* t = new trie(0);

    insert("abcd", t);
    insert("abdd", t);
    insert("abdc", t);
    insert("abcc", t);

    debug(t);

}