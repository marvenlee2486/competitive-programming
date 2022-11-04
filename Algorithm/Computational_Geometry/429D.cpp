#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

// struct point {
// 	ll x, y;
// 	point(ll x = 0, ll y = 0) : x(x), y(y) {}
    
//     // point as vector
// 	point operator + (const point a) { return point(x + a.x, y + a.y); }
// 	point operator - (const point a) { return point(x - a.x, y - a.y); }
// 	point operator * (double k) { return point(x * k, y * k); }
// 	point operator / (double k) { return point(x / k, y / k); }
    
// 	double operator * (const point& a)  const   { return x * a.x + y * a.y; } // dot product
// 	double operator % (const point& a)  const   { return x * a.y - y * a.x; } // cross product
    
//     // comparison between point / vector
//     bool operator==(const point& b)     const   {return abs(x - b.x)==0 && abs(y - b.y)==0;}
//     bool operator!=(const point& b)     const   {return !( *this == b);}
//     bool operator < (const point& a)    const   { return ((x < a.x) || (x == a.x &&  y < a.y) ); }
//     bool operator <= (const point& a)   const   { return (*this < a || *this == a) ; }
//     bool operator > (const point& a)    const   { return !(*this <= a);}
//     bool operator >= (const point& a)   const   {return (*this > a || *this == a); }

// 	point conj() { return point(x, -y); }
// 	ll norm() { return x * x + y * y; }
    
// 	double len() { return sqrt(norm()); }

// 	point rotate(double alpha) {
// 		double cosa = cos(alpha), sina = sin(alpha);
// 		return point(x * cosa - y * sina, x * sina + y * cosa);
// 	}
// };

typedef complex<long long> point;
#define x real()
#define y imag()

double dot(const point &a, const point &b) { return real(conj(a) * b); }
double cross(const point &a, const point &b) { return imag(conj(a) * b); }

// double cross(point p1, point p2, point p3){
//     return (p2-p1)%(p3-p2);
// }

bool compareX(const point& left, const point& right){
    return( left.x < right.x || (left.x == right.x && left.y <= right.y));
} 
bool compareY(const point& left, const point& right){
    return( left.y < right.y || (left.y == right.y && left.x <= right.x));
}
vector<point> ptx;
vector<point> pty;


ll cpop(vector<point> ptx, vector<point> pty){
    // O(log N)
    int n = ptx.size();
    int minx = ptx[0].x, maxx = ptx[n-1].x , midx = (minx+maxx)/2;
    
    // less than 3 points better edge case than d&c 
    if( ptx.size() <= 3){
        ll minv = INF;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                minv = min(minv, norm(ptx[i]-ptx[j]) );
            }
        }
        //  cout << "RET" << minv << "\n";
        return minv;
    }


    // O(N)
    // case where all the points have same x
    if( minx == maxx){
        ll minv = INF;
        for(int i = 1; i<n; i++){
            minv = min(minv, norm(ptx[i] - ptx[i-1]));
        }
        return minv;
    }

    vector<point> ptyl, ptyr, ptxl, ptxr;
    // O(N)
    for(int i=0 ; i < n; i++){
        point pt = pty[i];
        if(pt.x <= midx) ptyl.push_back(pt);
        else if(pt.x >midx) ptyr.push_back(pt);

        pt = ptx[i];
        if(pt.x <= midx) ptxl.push_back(pt);
        else if(pt.x >midx) ptxr.push_back(pt);
    }
    
    ll mindsq = min(cpop(ptxl,ptyl), cpop(ptxr,ptyr));
    ll mind = sqrt(mindsq) + 1;
    
    // O(N)
    vector<point> ptl , ptr;
    for(int i=0 ; i < n; i++){
        point pt = pty[i];

        if(pt.x <= midx && pt.x >= midx - mind) ptl.push_back(pt);
        else if(pt.x >midx && pt.x <= midx+ mind) ptr.push_back(pt);
    }
    

    // cout << ptl.size() << " " << ptr.size() << "\n";
    int idxy = 0;

    // O(N * 6)
    for(int i = 0; i < ptl.size(); i++){
        
        while( idxy < ptr.size() && ptr[idxy].y < ptl[i].y - mind ) idxy++;
        if(idxy == ptr.size()) break;
        // Check the six point
        int idend = min( (int)ptr.size() - 1, idxy + 6);
        for(int j = idxy ; j <= idend; j++){
            // cout << ptl[i].x << " " << ptl[i].y << " " << ptr[j].x << " " << ptr[j].y << "\n";
            mindsq = min(mindsq, norm(ptl[i] - ptr[j]) );
        }

    }

    return mindsq;
}


void solve(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int xx; cin >> xx;
        sum += xx;
        ptx.push_back(point(i+1,sum));
        pty.push_back(point(i+1,sum));
    }
    sort(ptx.begin(),ptx.end(),compareX);
    sort(pty.begin(),pty.end(),compareY);

    cout << cpop(ptx,pty) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}