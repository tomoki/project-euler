#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <omp.h>

using namespace std;
#define all(c) c.begin(),c.end()

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& val){
    os << "[ ";
    for(typename vector<T>::const_iterator it=val.begin();
        it != val.end();++it){
        os << *it << " ";
    }
    os << "]";
    return os;
}

typedef long long ll;
ll gcd(ll a,ll b){
    return b==0 ? a : gcd(b,a%b);
}

ll lcm(ll a,ll b){
    if(a < 0) a *= -1;
    if(b < 0) b *= -1;
    return a*b / gcd(a,b);
}

struct Fraction{
    ll n,d;
    Fraction(ll _n,ll _d){
        ll c = lcm(_n,_d);
        n = c / _d;
        d = c / _n;
        if(d < 0){
            n *= -1;
            d *= -1;
        }
    }

    Fraction(ll _n){
        Fraction(_n,1);
    }

    bool operator<(const Fraction& r) const{
        ll c_d = lcm(d,r.d);
        return n*(c_d/d)< r.n*(c_d/r.d);
    }
    bool operator>(const Fraction& r) const{
        return not ((*this) < r or (*this) == r);
    }
    bool operator<=(const Fraction& r) const{
        return (*this) < r or (*this) == r;
    }
    bool operator>=(const Fraction& r) const{
        return (*this) > r or (*this) == r;
    }
    bool operator==(const Fraction& r) const{
        return n == r.n and d == r.d;
    }
    Fraction operator+(const Fraction& r) const{
        ll c_d = lcm(d,r.d);
        return Fraction(n*(c_d/d)+r.n*(c_d/r.d),c_d);
    }
    Fraction operator-(const Fraction& r) const{
        return (*this) + (-r);
    }
    Fraction operator*(const Fraction& r) const{
        return Fraction(n*r.n,d*r.d);
    }
    Fraction operator/(const Fraction& r) const{
        return (*this) * Fraction(r.d,r.n);
    }
    Fraction operator+() const{
        return Fraction(n,d);
    }
    Fraction operator-() const{
        return (*this) * -1;
    }
    Fraction operator*(const ll& a) const{
        return Fraction(a*n,d) ;
    }
};

ostream& operator<<(ostream &os,const Fraction& f){
    os << f.n << "/" << f.d;
    return os;
}

int main(){
    ll N = 1000000;

    vector<Fraction> vec;
    Fraction want(3,7);
    for(ll d=2;d<=N;d++){
        ll l_n = 1;
        ll u_n= d;
        for(int i=0;i<100;i++){
            ll m_n = (l_n + u_n) / 2;
            Fraction cont(m_n,d);
            if(cont >= want){
                u_n = m_n;
            }else{
                l_n = m_n;
            }
        }
        vec.push_back(Fraction(l_n,d));
    }
    sort(all(vec));
    cout << *(lower_bound(all(vec),want)-1) << endl;
    return 0;
}
