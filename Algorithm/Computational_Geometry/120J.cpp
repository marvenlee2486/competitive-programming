#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

typedef complex<long long> point;
#define x() real()
#define y() imag()

bool compareX(const pair<point,int>& l, const pair<point,int>& r){
    point left = l.first, right = r.first;
    return( left.x() < right.x() || (left.x() == right.x() && left.y() <= right.y()));
} 
bool compareY(const pair<point,int>& l, const pair<point,int>& r){
    point left = l.first, right = r.first;
    return( left.y() < right.y() || (left.y() == right.y() && left.x() <= right.x()));
}

ll cpop(vector<pair<point,int>> ptx, vector<pair<point,int>> pty, pair<point, int>* One, pair<point, int>* Two){
    // O(log N)
    int n = ptx.size();
    int minx = ptx[0].first.x(), maxx = ptx[n-1].first.x() , midx = (minx+maxx)/2;
     cout << minx << " " << maxx << "\n";
    // less than 3 points better edge case than d&c 
    if( ptx.size() <= 3){
        ll minv = INF;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(ptx[i].second == ptx[j].second) continue;
                if( norm(ptx[i].first-ptx[j].first) < minv ){
                    minv = norm(ptx[i].first-ptx[j].first);
                    *One = ptx[i];
                    *Two = ptx[j];
                }
            }
        }
        //  cout << "RET" << minv << "\n";
        return minv;
    }


    // O(N)
    // case where all the points have same x
    if( abs(  minx - maxx ) <=1 ){
        ll minv = INF;
        for(int i = 1; i<n; i++){
            if( ptx[i].second == ptx[i-1].second) continue;
            if( norm(ptx[i].first-ptx[i-1].first) < minv ){
                minv = norm(ptx[i].first-ptx[i-1].first);
                *One = ptx[i];
                *Two = ptx[i-1];
            }
        }
        return minv;
    }

    vector<pair<point,int> > ptyl, ptyr, ptxl, ptxr;
    // O(N)
    for(int i=0 ; i < n; i++){
        point pt = pty[i].first;
        if(pt.x() <= midx) ptyl.push_back(pty[i]);
        else if(pt.x() >midx) ptyr.push_back(pty[i]);

        pt = ptx[i].first;
        if(pt.x() <= midx) ptxl.push_back(ptx[i]);
        else if(pt.x() >midx) ptxr.push_back(ptx[i]);
    }
    pair<point, int> t1,t2;
    
    ll mindsq1 = cpop(ptxl,ptyl, &t1, &t2);
    ll mindsq2 = cpop(ptxr,ptyr,One,Two);
    ll mindsq =  min(mindsq1,mindsq2);
    if(mindsq1 < mindsq2 ){
        *One = t1;
        *Two = t2;
    }
    ll mind = sqrt(mindsq) + 1;
    
    // O(N)
    vector<pair<point,int > > ptl , ptr;
    for(int i=0 ; i < n; i++){
        point pt = pty[i].first;

        if(pt.x() <= midx && pt.x() >= midx - mind) ptl.push_back(pty[i]);
        else if(pt.x() >midx && pt.x() <= midx+ mind) ptr.push_back(pty[i]);
    }
    

    //cout << ptl.size() << " " << ptr.size() << "\n";
    int idxy = 0;

    // O(N * 6)
    for(int i = 0; i < ptl.size(); i++){
        
        while( idxy < ptr.size() && ptr[idxy].first.y() < ptl[i].first.y() - mind ) idxy++;
        if(idxy == ptr.size()) break;
        // Check the six point
        int idend = min( (int)ptr.size() - 1, idxy + 6);
        for(int j = idxy ; j <= idend; j++){
            if (ptl[i].second == ptr[j].second) continue;
            // cout << ptl[i].x << " " << ptl[i].y() << " " << ptr[j].x << " " << ptr[j].y() << "\n";
            mindsq = min(mindsq, norm(ptl[i].first - ptr[j].first) );
            if( norm(ptl[i].first-ptr[j].first) < mindsq ){
                    mindsq = norm(ptl[i].first-ptr[j].first);
                    *One = ptx[i];
                    *Two = ptx[j];
            }
        }

    }

    return mindsq;
}


void solve(){
    int n;
    cin >> n;
    vector<pair<point, int> > ptx;
    vector<pair<point, int> > pty;
    vector<point> original;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        ptx.emplace_back(point(x,y),i);
        pty.emplace_back(point(x,y),i);
        ptx.emplace_back(point(-x,y),i);
        pty.emplace_back(point(-x,y),i);
        ptx.emplace_back(point(x,-y),i);
        pty.emplace_back(point(x,-y),i);
        ptx.emplace_back(point(-x,-y),i);
        pty.emplace_back(point(-x,-y),i);
        original.emplace_back(point(x,y));
    }
    sort(ptx.begin(),ptx.end(),compareX);
    sort(pty.begin(),pty.end(),compareY);
    pair<point,int> t1,t2;
    cpop(ptx,pty, &t1, &t2);
    cout << t1.second+1 << " ";
    cout << ((t1.first.x() - original[t1.second].x())!=0)*2 + ((t1.first.y() - original[t1.second].y())!=0) +1 << " ";
    cout << t2.second+1 << " ";
    cout << ((t2.first.x() - original[t2.second].x())!=0)*2 + ((t2.first.y() - original[t2.second].y())!=0) +1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}