#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define eb emplace_back
const int N = 1e3+2;
vector< vector<int> > v;
vector< vector<ii> > col;
vector<int> buffer;
int n;
vector<ii> ans;
int ns = 0;
bool pilot[N];
bool solve[N];

int choose(){
    int chosen =-1;
    // cout << "SPECIAL" << col[3][0].first << " " << col[3][1].first << " " << col[3][2].first << "\n";
    for(int i=1;i<n+1;i++){
       
        
        if(solve[i])continue;
        
        if(col[i][0].second == col[i][1].second && col[i][1].second == col[i][2].second){
            solve[i] = true;
            pilot[col[i][0].second] = true;
            ns++;
            continue;
        }
       
        if(col[i][0].first == col[i][1].first && col[i][2].first == col[i][1].first ) continue;
  
        if(col[i][0].first != 0 && col[i][1].first != 0 && col[i][2].first != 0) continue;

        chosen = i;
        break;
    }
    return chosen;
}

void move(int x, int y){
    int colour = v[x].back();
    int old_row = v[x].size() -1;
    int new_row = v[y].size();
    v[y].eb(colour);
    v[x].pop_back();
    //cout << old_row << " " << x << "HEHE\n";
    for(int i =0;i<3;i++){
        
        //cout << col[colour][i].first << " " << col[colour][i].second << "\n";
        if( col[colour][i] == ii(old_row,x) ){
            col[colour][i] = ii(new_row,y);
            break;
        }
        // if(i==2){
        //     cout << "FALSEEE\n";
        // }
    }
    buffer.insert(buffer.begin(),x);
    //cerr << x+1 << " " << y+1 << "\n";
    ans.eb(x+1,y+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    
    v.assign(n+1, vector<int>());
    col.assign(n+1, vector<ii>());

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            int test;
            cin >> test;
            v[j].push_back(test);
            col[test].emplace_back(2-i,j);
        }
    }
    for(int j=0;j<n;j++){
        reverse(v[j].begin(),v[j].end());
    }
    
    buffer.emplace_back(n);
    buffer.emplace_back(n);
    buffer.emplace_back(n);
    
    // O(n)
    int idx=0;
    while(ns!=n){
        // O(n)
        int chosen = choose();
        if(chosen == -1){
            //cerr << "CHOSEN\n";

            
            for(int i = 0;i<=n;i++){
                if(!pilot[i] && v[i].size()!=0){
                    while(v[i].size()!=0){
                        while(buffer.back()==i){
                            buffer.insert(buffer.begin(),buffer.back());
                            buffer.pop_back();
                        }
                            
                        move(i,buffer.back());
                        buffer.pop_back();
                    }    
                    break;
                }
            }
            continue;
        }
        idx = 0;
        //cerr << "BUFFER:: " << buffer[0] << " " << buffer[1] << " " << buffer[2] << "\n";
        vector<ii> &colour = col[chosen];
        sort(colour.begin(),colour.end());


        if(colour[0].first ==0 && colour[1].first==0 && colour[2].first ==1){
            if(colour[0].second == colour[2].second  || colour[1].second == colour[2].second){
                //cerr <<"CASE 001 (01 same):\n";
                // case 001 (01 same)
                if(colour[1].second == colour[2].second){
                    swap(colour[0],colour[1]);
                }
                if(v[colour[0].second].size()==3){
                    while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                    move(colour[0].second,buffer.back());
                    buffer.pop_back();
                }
                while(v[colour[1].second].size()!=1){
                    while(buffer.back() == colour[0].second || buffer.back()==colour[1].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                    move(colour[1].second,buffer.back());
                    buffer.pop_back();
                }
                move(colour[1].second, colour[0].second);
                buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
            }
            else{
                //cerr <<"CASE 001 (01 diff):\n";
                // case 001 (01 differnt)
                while(v[colour[0].second].size()!=1){
                    while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                    move(colour[0].second,buffer.back());
                    buffer.pop_back();
                }
                while(v[colour[2].second].size()!=2){
                    while(buffer.back() == colour[0].second || buffer.back()==colour[2].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                    move(colour[2].second,buffer.back());
                    buffer.pop_back();
                }
                move(colour[2].second, colour[0].second);
                buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));

                while(v[colour[1].second].size()!=1){
                    while(buffer.back() == colour[0].second || buffer.back()==colour[1].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                    move(colour[1].second,buffer.back());
                    buffer.pop_back();
                }
                move(colour[1].second, colour[0].second);
                buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
            }
        }

        // case 002 
        else if(colour[0].first ==0 && colour[1].first==0 && colour[2].first ==2){
            // test
            //cerr <<"CASE 002:\n";
            if(colour[2].second == colour[0].second) swap(colour[0],colour[1]);
            while(v[colour[0].second].size()!=1){
                while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[0].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[2].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
    
            while(v[colour[1].second].size()!=1){
                while(buffer.back() == colour[0].second || buffer.back()==colour[1].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[1].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[1].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
        }

        // case 012 (01 different)
       // TODO;
        else if(colour[0].first ==0 && colour[1].first==1 && colour[2].first ==2 && colour[0].second != colour[1].second){ 
            //cerr <<"CASE 012 (01 diff):\n";
            while(v[colour[0].second].size()!=1){
                while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[0].second,buffer.back());
                buffer.pop_back();
            }

            while(v[colour[1].second].size()!=2){
                while(buffer.back() == colour[0].second || buffer.back()==colour[1].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[1].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[1].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));


            while(v[colour[2].second].size()!=colour[2].first+1){
                while(buffer.back() == colour[0].second || buffer.back()==colour[2].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[2].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[2].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));       
        }
        // case 012 (01 same)
        else if(colour[0].first ==0 && colour[1].first==1 && colour[2].first ==2 && colour[0].second == colour[1].second){
            //cerr <<"CASE 012 (01 same):\n";
            while(v[colour[0].second].size()!=2){
                while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[0].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[2].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
        }
        // case 011 (01 different)
        else if(colour[0].first ==0 && colour[1].first==1 && colour[2].first ==1 && colour[0].second != colour[1].second &&  colour[0].second != colour[2].second ){
            //cerr <<"CASE 011 (01 diff):\n";
            while(v[colour[0].second].size()!=1){
                while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[0].second,buffer.back());
                buffer.pop_back();
            }
            while(v[colour[1].second].size()!=2){
                while(buffer.back() == colour[0].second || buffer.back()==colour[1].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[1].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[1].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));

            while(v[colour[2].second].size()!=2){
                while(buffer.back() == colour[0].second || buffer.back()==colour[2].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[2].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[2].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
        }
        // case 022
        else if (colour[0].first ==0 && colour[1].first==2 && colour[2].first ==2){
            //cerr <<"CASE 022:\n";
            //cout << colour[0].second << " " << colour[1].second << " " << colour[2].second << "BBBB\n";
            while(v[colour[0].second].size()!=1){
                while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[0].second,buffer.back());
                buffer.pop_back();
            }

            if(colour[1].first == 2){
                //cout << colour[1].second << " " << colour[2].second << "???\n";
                move(colour[1].second, colour[0].second);
                buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
                //cout << colour[2].second << "???\n";
                while(v[colour[2].second].size()!= colour[2].first +1 ){
                    while(buffer.back() == colour[0].second || buffer.back()==colour[2].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                    move(colour[2].second,buffer.back());
                    buffer.pop_back();
                }
                //cout << colour[2].second << "???\n";
                move(colour[2].second, colour[0].second);
                buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));

            }
            else{
                move(colour[2].second, colour[0].second);
                buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));

                while(v[colour[1].second].size()!= colour[1].first +1 ){
                    while(buffer.back() == colour[0].second || buffer.back()==colour[1].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                    move(colour[1].second,buffer.back());
                    buffer.pop_back();
                }
                move(colour[1].second, colour[0].second);
                buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));

            }
        }
        // case 011 (01 same)
        else{
            //cerr <<"CASE 011 (01 same):\n";
            if(colour[0].second == colour[2].second) swap(colour[2],colour[1]);
            while(v[colour[0].second].size()!=2){
                while(buffer.back() == colour[0].second || buffer.back()==colour[0].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[0].second,buffer.back());
                buffer.pop_back();
            }
            while(v[colour[2].second].size()!=2){
                while(buffer.back() == colour[0].second || buffer.back()==colour[2].second){
                        buffer.insert(buffer.begin(),buffer.back());
                        buffer.pop_back();
                    }
                move(colour[2].second,buffer.back());
                buffer.pop_back();
            }
            move(colour[2].second, colour[0].second);
            buffer.erase( find(buffer.begin(),buffer.end(),colour[0].second));
        }
        ns++;
        pilot[colour[0].second] = true;
        solve[chosen] = true;
    }
    if(v[n].size()!=0){
        move(n,buffer.back());
        buffer.pop_back();
        move(n,buffer.back());
        buffer.pop_back();
        move(n,buffer.back());
        buffer.pop_back();       
    }

    cout << ans.size() << "\n";
    for(auto&[x,y]:ans) cout << x << " " << y << "\n";
}