#include<bits/stdc++.h>
using namespace std;

struct node{
    bool isope;
    bool isconstant;
    node* left;
    node* right;
    string s;
    node(string s):s(s){
        if(s == "*" || s == "-" || s == "+") isope = true;
        else isope = false;
        isconstant = false;
        if(!isope){
            try{
                stol(s);
                isconstant = true;
            }
            catch(exception e){
                
            }
            
        }
    }
};

void recur(node* cur){
    if( ! cur->isope) return;

    string s;
    cin >> s;
    cur->left = new node(s);
    recur(cur->left);
    cin >> s;
    cur->right = new node(s);
    recur(cur->right);

    if(!cur->left->isconstant || !cur->right->isconstant ) return;

    cur->isope = false;
    if(cur->s == "+"){
        cur->s = to_string(stol(cur->left->s) + stol (cur->right->s));
    } else if(cur->s == "-"){
        cur->s = to_string(stol(cur->left->s) - stol (cur->right->s));
    } else {
        cur->s = to_string(stol(cur->left->s) * stol (cur->right->s));
    }
    cur->left = NULL;
    cur->right = NULL;
    cur->isconstant = true;
    return;
}

void print(node* cur){
    cout << cur->s << " ";
    if(!cur->isope) return;

    print(cur->left);
    print(cur->right);
}

void solve(string s){
    node* root = new node(s);
    recur(root);

    print(root);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int cnt = 1;
    string s;
    while(cin >> s){
        cout << "Case " << cnt << ": ";
        solve(s);
        cout << "\n";
        cnt++;
    }
}