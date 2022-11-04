#include <bits/stdc++.h>
using namespace std;

int q(int x1, int y1, int x2, int y2){
   cout << "? "<< x1 << " " << y1 << " " << x2 << " " << y2 << endl;
   int x;
    cin >> x;
    return x;
}

struct point{
    int x1, y1;
    int xl,xr,yl,yr;
    point(){}
    point(int n):xl(1),xr(n),yl(1),yr(n){}
};

struct rectangle{
    point pt[2];
    rectangle(int n){
        pt[0] = point(n);
        pt[1] = point(n);
    }
};
int n;
void binsearch(rectangle &r1, rectangle &r2){
    int lr = 1;
    while(r1.pt[lr].xl < r1.pt[lr].xr){
        int mid = (r1.pt[lr].xl + r1.pt[lr].xr)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,mid,n);
        else
            ret = q(mid,1,n,n);
            
        if(ret == 0){
            r2.pt[lr].xl = mid+1;
            r1.pt[lr].xl = mid+1;
        }
        else if( ret ==2){
            r2.pt[lr].xr = mid;
            r1.pt[lr].xr = mid;
        }else{
            r1.pt[lr].xr = mid;
        }
    }

    while(r2.pt[lr].xl < r2.pt[lr].xr){
        int mid = (r2.pt[lr].xl + r2.pt[lr].xr)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,mid,n);
        else
            ret = q(mid,1,n,n);
            
        if(ret == 0 || ret == 1){
            r2.pt[lr].xl = mid+1;
        }
        else if( ret ==2){
            r2.pt[lr].xr = mid;
        }
    }
    // search for y

    while(r1.pt[lr].yl < r1.pt[lr].yr){
        int mid = (r1.pt[lr].yl + r1.pt[lr].yr)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,n,mid);
        else
            ret = q(1,mid,n,n);
            
        if(ret == 0){
            r2.pt[lr].yl = mid+1;
            r1.pt[lr].yl = mid+1;
        }
        else if( ret ==2){
            r2.pt[lr].yr = mid;
            r1.pt[lr].yr = mid;
        }else{
            r1.pt[lr].yr = mid;
        }
    }

    while(r2.pt[lr].yl < r2.pt[lr].yr){
        int mid = (r2.pt[lr].yl + r2.pt[lr].yr)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,n,mid);
        else
            ret = q(1,mid,n,n);
            
        if(ret == 0 || ret == 1){
            r2.pt[lr].yl = mid+1;
        }
        else if( ret ==2){
            r2.pt[lr].yr = mid;
        }
    }

    /// Change the left one 
    lr = 0;
    while(r2.pt[lr].xl < r2.pt[lr].xr){
        int mid = (r2.pt[lr].xl + r2.pt[lr].xr+1)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,mid,n);
        else
            ret = q(mid,1,n,n);
            
        if(ret == 0){
            r1.pt[lr].xr = mid-1;
            r2.pt[lr].xr = mid-1;
        }
        else if( ret ==2){
            r1.pt[lr].xl = mid;
            r2.pt[lr].xl = mid;
        }else{
            r2.pt[lr].xl = mid;
        }
    }

    while(r1.pt[lr].xl < r1.pt[lr].xr){
        int mid = (r1.pt[lr].xl + r1.pt[lr].xr+1)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,mid,n);
        else
            ret = q(mid,1,n,n);
            
        if(ret == 0 || ret == 1){
            r1.pt[lr].xr = mid-1;
        }
        else if( ret ==2){
            r1.pt[lr].xl = mid;
        }
    }
    // search for y
    while(r2.pt[lr].yl < r2.pt[lr].yr){
        int mid = (r2.pt[lr].yl + r2.pt[lr].yr+1)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,n,mid);
        else
            ret = q(1,mid,n,n);
            
        if(ret == 0){
            r1.pt[lr].yr = mid-1;
            r2.pt[lr].yr = mid-1;
        }
        else if( ret ==2){
            r2.pt[lr].yl = mid;
            r1.pt[lr].yl = mid;
        }else{
            r2.pt[lr].yl = mid;
        }
    }

    while(r1.pt[lr].yl < r1.pt[lr].yr){
        int mid = (r1.pt[lr].yl + r1.pt[lr].yr+1)/2;
        int ret;
        if(lr == 1)
            ret = q(1,1,n,mid);
        else
            ret = q(1,mid,n,n);
            
        if(ret == 0 || ret == 1){
            r1.pt[lr].yr = mid-1;
        }
        else if( ret ==2){
            r1.pt[lr].yl = mid;
        }
    }

}

bool correct( int x11,int y11,int x12,int y12, int x21, int y21,int x22,int y22){
    if(x11>x12 || y11 > y12 || x21 > x22 || y21 > y22) return false;
    return q(x11,y11,x12,y12) == 1 && q(x21,y21,x22,y22) == 1;
}

int main(){
    cin >> n;
    
    //rectangle[] r = {rectangle(n), rectangle(n)};
    rectangle r1(n);
    rectangle r2(n);

    binsearch(r1,r2);

    int x11,x12,x21,x22,y11,y12,y21,y22;
    x11 = r1.pt[0].xl;
    y11 = r1.pt[0].yl;
    x12 = r1.pt[1].xl;
    y12 = r1.pt[1].yl;

    x21 = r2.pt[0].xl;
    y21 = r2.pt[0].yl;
    x22 = r2.pt[1].xl;
    y22 = r2.pt[1].yl;

    // swap y11, swap x12, swap x22;
    int change = 0;
    while(!correct(x11,y11,x12,y12,x21,y21,x22,y22)){
        if( change %2 ) swap(y11,y21);
        if( (change/2) %2) swap(x12,x22);
        if( (change/4) %2 )swap(y22,y12);
        change++;
        if( change %2 ) swap(y11,y21);
        if( (change/2) %2) swap(x12,x22);
        if( (change/4) %2 )swap(y22,y12);
    }
    
    cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " "
    << x21 << " " << y21 << " " << x22 << " " << y22 << endl;  
    


    return 0;
}