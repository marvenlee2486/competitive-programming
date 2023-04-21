#include <bits/stdc++.h>
using namespace std;
int k,n;
vector<int> records [101];
unordered_map<int,int> hash_records[101];
int ans[1000];
int dir(int test, int compare){
    if(test < compare) return -1;
    else if (test > compare) return 1;
    return 0;
}

// return the root
int find_root(int l, int r){
    if(l == r) return l;
    for(int root_idx = l + 1; root_idx <= r - 1; root_idx++ ){
        
        // Take the first Record as control (to compare)
        int control_idx = root_idx;
        int root = records[0][root_idx];

        vector<int> control; // Left of root for record 0
        vector<int> control2; // Right of root for record 0
        for(int j = l; j < control_idx; j++) control.emplace_back(records[0][j]);
        for(int j = control_idx + 1; j <= r; j++) control2.emplace_back(records[0][j]);

        bool is = true;
        // Loop For each Records
        for(int ridx = 1; ridx < k; ridx++){
            // The original Control_idx not important, this control_idx means the root_idx for record ridx
            control_idx = hash_records[ridx][root];

            // Check the Left one 
            int test_idx = hash_records[ridx][*control.begin()];
            for(int c : control){
                if(dir(test_idx,control_idx) != dir(hash_records[ridx][c],control_idx)) is = false;
                //if(!is) break;
            }
            //if(!is) break;
            // Check the Right one
            int test_idx2 = hash_records[ridx][*control2.begin()];
            for(int c : control2){
                if(dir(test_idx2,control_idx) != dir(hash_records[ridx][c],control_idx)) is = false;
                //if(!is) break;
            }
            //if(!is) break;  

            // Need to ensure the Left one and Right one are different.
            if(dir(test_idx, control_idx) == dir(test_idx2, control_idx)) is = false;
        }
        if(is) return root;       
    }
    assert(false);
}

int recur(int l, int r){
    if(l == r) return records[0][l];
    int root = find_root(l, r);
    int root_idx = hash_records[0][root];
    assert(root_idx > l && root_idx < r);

    int left_root = recur(l, root_idx - 1);
    int right_root = recur(root_idx + 1, r);

    ans[left_root] = root;
    ans[right_root] = root;

    return root;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            int c; cin >> c;
            records[i].push_back(c);
            hash_records[i][c] = j;
        }
    }

    recur(0,n - 1);
    
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 0) ans[i] = -1;
        cout << ans[i] << " ";
    }
}