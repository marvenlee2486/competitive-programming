#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
struct fraction{
    ll u,d;
    fraction(ll u, ll d):u(u),d(d){}

    fraction operator+(fraction x){
        ll nu = this->u * x.d + this->d * x.u;
        ll nd = this->d * x.d;

        ll g = __gcd(u,d);
        nu /= g;
        nd /= g;
        return fraction(nu,nd);
    }

    fraction operator-(fraction x){
        ll nu = this->u * x.d - this->d * x.u;
        ll nd = this->d * x.d;

        ll g = __gcd(u,d);
        nu /= g;
        nd /= g;
        return fraction(nu,nd);
    }

    fraction operator*(fraction x){
        ll nu = this->u * x.u;
        ll nd = this->d * x.d;

        ll g = __gcd(u,d);
        nu /= g;
        nd /= g;
        return fraction(nu,nd);
    }

    fraction operator/(fraction x){
        return (*this) * fraction(x.d,x.u);
    }
};

void print(fraction x){
    while(x.d != 0) {

        cout << x.u / x.d << " ";
        x.u = x.u % x.d;
        x = fraction(1, 1) / x;
    }
    cout << "\n";
}
int main(){
    int n1,n2;
    cin >> n1 >> n2;
    vector<int> a1(n1),a2(n2);
    for(auto &i : a1) cin >> i;
    for(auto &i : a2) cin >> i;
    fraction cur(a1[n1 - 1],1);
    for(int i = n1 - 2; i >= 0; i--){
       // cout << i << "th \n";
        //cout << cur.u << " " << cur.d << "\n";
        cur = fraction(1,1) / cur;
        //cout << cur.u << " " << cur.d << "\n";
        cur = cur + fraction(a1[i],1);
        //cout << cur.u << " " << cur.d << "\n";
    }

  
    fraction r1 = cur;
    cur = fraction(a2[n2 - 1],1);
    for(int i = n2 - 2; i >= 0; i--){
        cur = fraction(1,1) / cur;
        cur = cur + fraction(a2[i],1);
        
    }
    fraction r2 = cur;
    // cout << r1.u << " " << r1.d << "\n";
    // cout << r2.u << " " << r2.d << "\n";

    fraction ans = r1 - r2;
    //cout << "TEST" << ans.u << " " << ans.d << "\n";
    print(r1 + r2);
    print(r1 - r2);
    print(r1 * r2);
    print(r1 / r2);
    
}