#include<bits/stdc++.h>
using namespace std;

struct tenant{
    int qmin, qbase, qmax;
    int dsize;
    int pri;

    tenant(int l){
        pri = l;
    }
    unordered_map<int, int> p2b;
    unordered_map<int, int> recent_time;
    set< pair<int, int> > pq;
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, q, m;
    cin >> n >> q >> m;
    vector<tenant> arr;
    for(int i = 0; i < n; i++){
        int l; cin >> l;
        arr.emplace_back(l);
    }
    for(int i = 0; i < n; i++){
       cin >> arr[i].dsize;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i].qmin >> arr[i].qbase >> arr[i].qmax;
    }

    int last = 1;

    for(int t = 0; t < m; t++){
        int id, page;
        cin >> id >> page;
        id--;

        // page hit
        if(arr[id].p2b.find(page) != arr[id].p2b.end()){
            cout << arr[id].p2b[page] << endl;
            
            // arr[id].pq.erase(pair<int,int>(arr[id].recent_time[page], page));
            arr[id].recent_time[page] = t;
            arr[id].pq.emplace(t, page);
            continue;
        }
        
        // allocate the buffer to that tenant
        if(arr[id].p2b.size() < arr[id].qmax && last < q){
            cout << last << endl;
            arr[id].p2b[page] = last;
            arr[id].pq.emplace(t , page);
            arr[id].recent_time[page] = t;
            last++;
        }
        else{
            while( arr[id].recent_time[arr[id].pq.begin()->second] != arr[id].pq.begin()->first){
                arr[id].pq.erase(arr[id].pq.begin());
            }
            auto[_, dirty] = *arr[id].pq.begin();
            arr[id].pq.erase(arr[id].pq.begin());

            int rep = arr[id].p2b[dirty];
            cout << rep << endl;

            arr[id].p2b.erase(dirty);
            arr[id].p2b[page] = rep;
            arr[id].p2b.emplace(t , page);
            arr[id].recent_time[page] = t;
        }
    }


}


