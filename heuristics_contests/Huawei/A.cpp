#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;
int t = 0;
ll sumqbase = 0;
struct tenant{
    int qmin, qbase, qmax;
    int dsize;
    int priority;
    int q; // n page in buffer
    int id;
    tenant(int l, int id):id(id){
        priority = l;
    }
    unordered_map<int, int> p2b; // page in memory to page in buffer
    unordered_map<int, int> recent_time; // page in memory recent time.
    unordered_set<int> second;
    set< pair<int, int> > pq; // priority of time page in memory
    // return true if page hit
    
    ld priority_score(){
        ld frac = ll(qbase - q) * 1.0/ qbase; //(ld(sumqbase) * 1.0 / (qbase * qbase)) ;
        // frac = round(frac * 10) / 10;
        // cout << frac << "\n";
        return 3 * priority * frac * abs(frac);
    }
    int remove_page(int page){
        pq.erase(pq.find(ii(recent_time[page], page)));
        recent_time.erase(page);
        second.erase(page);
        int ret = p2b[page];
        p2b.erase(page);
        q--;
        return ret;
    }

    void add_page(int page, int buf){
        //if(recent_time.find(page) != recent_time.end()) remove_page(page);
        recent_time[page] = t;
        p2b[page] = buf;
        pq.emplace(t,page);
        q++;
    }

    void update_page(int from, int to){
        add_page(to,remove_page(from));
    }


    bool page_hit(int page){
        return p2b.find(page) != p2b.end();
    }

    // empty the LRU, return the buffer_id
    int pop(){
        auto[_, replace] = *pq.begin();
        return remove_page(replace);
    }

    // replace the LRU with page
    int replace_LRU(int page){
        // if(page_hit(page)){
        //     update_page(page, page);
        //     return p2b[page];
        // }
        // page_fault
        int replace;
        auto it = pq.begin();
        while (true){
            auto[_, rep] = *it;
            it++;
            if(second.find(rep) == second.end()) second.insert(rep);
            else {
                replace = rep;
                break;
            }
            if(it == pq.end()) it = pq.begin();
        }
        update_page(replace, page);

        return p2b[page];
    }   

    void debug(){
        printf("Tenant id = %d\n", id + 1);
        printf("qmin = %d, qbase = %d, qmax = %d\n", qmin, qbase, qmax);

        printf("Memory in Buffer, size = %d \n", q);
        assert(pq.size() == p2b.size() && pq.size() == recent_time.size() && q == pq.size());
        for(auto[page, buff]: p2b){
            int time = recent_time[page];
            printf("page = %d, Buffer = %d, Recent = %d\n", page, buff, time);
            assert(pq.find(ii(recent_time[page],page)) != pq.end());
        }
        printf("\n");
    }
};


// heuristics score of priority
        // replace those with greater (q - qbase) or self.
        // replace those with LRU and see possible or not
    
struct database{
    vector<tenant*> arr;
    set<pair<ld,int>> diff;  
    int n;

    int total;
    int cur;


    void remove_diff(int x){
        diff.erase(pair<ld,int>(arr[x]->priority_score(), x));
    }

    void add_diff(int x){
        diff.emplace(arr[x]->priority_score(), x);
    }

    database(vector<tenant*> arr, int total):arr(arr), total(total){
        n = arr.size();
        for(int i = 0; i < n; i++){
            add_diff(i);
        }
        cur = 1;
    }

    
    // can tenant x replace tenant y
    bool can_replace(int x,int y){
        if (y == n){
            // replace a buffer that not in used.
            if (cur > total) return false;
            return arr[x]->q < arr[x]->qmax;
        }
        if (x == y) return arr[x]->q >= arr[x]->qmin && arr[x]->q <= arr[x]->qmax;
        return arr[x]->q < arr[x]->qmax && arr[y]->q > arr[y]->qmin;
    }
    // x replace y
    int replace(int x, int y, int x_page){
        if(y == n){
            remove_diff(x);
            // special case;
            arr[x]->add_page(x_page,cur);
            add_diff(x);
            cur += 1;
            return cur - 1;
        }
        if(x == y){
            return arr[x]->replace_LRU(x_page);
        }
        remove_diff(x);
        remove_diff(y);

        int buff = arr[y]->pop();
        arr[x]->add_page(x_page,buff);

        add_diff(x);
        add_diff(y);
        return buff;
    }

    int operation(int id, int page){
        if(arr[id]->page_hit(page)){
            arr[id]->update_page(page, page);
            return arr[id]->p2b[page];
        }
        // first replace empty buffer
        if(can_replace(id, n)) return replace(id, n, page);
        
        // replace the one that would reduce deviation
        for(auto[_, rep]: diff){
            if(can_replace(id,rep)) 
                return replace(id, rep, page);   
        }
        assert(false);
    }


    void debug(){
        cout << "t = " << t <<  "\n";
        for(int i = 0; i < n; i++) arr[i]->debug();
    }
    
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, q, m;
    cin >> n >> q >> m;
    vector<tenant*> arr;
    // arr.emplace_back(new tenant(0));
    for(int i = 0; i < n; i++){
        int l; cin >> l;
        arr.emplace_back(new tenant(l,i));
    }
    for(int i = 0; i < n; i++){
       cin >> arr[i]->dsize;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i]->qmin >> arr[i]->qbase >> arr[i]->qmax;
        sumqbase += arr[i]->qbase;
    }

    database data(arr,q);

    while(t < m){
        int id, page;
        cin >> id >> page;
        id--;
        cout << data.operation(id, page) << endl;
        // data.debug();
        t++;
    }

}


