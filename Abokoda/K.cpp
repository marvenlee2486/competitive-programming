#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> q;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        q.push_back(c);
    }
    for(int i = n - 1; i > 1; i--){
        while(q[0] != i){
            cout << "P";
            q.push_back(q[0]);
            q.pop_front();
        }

        while(q[1] != i + 1){
            cout << "SP";
            
            q.push_back(q[1]);
            q.pop_front();
            q.pop_front();
            q.push_front(i);
        }
    }
    while(q[0] != 1){
        cout << "P";
        q.push_back(q[0]);
        q.pop_front();
    }
    cout << "\n";
    // for(int i = 0; i < n; i++){
    //             cout << q[i] << " ";
    //         }
    //         cout << "\n";
}