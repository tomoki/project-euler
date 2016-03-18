#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

const double EPS = 1e-9;

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


vector<bool> sieve(ll M){
    vector<bool> isPrime(M,false);
    for(ll i=2;i<M;i++) isPrime[i] = true;
    for(ll i=2;i*i<M;i++){
        if(not isPrime[i]) continue;
        for(ll j=i*i;j<M;j+=i){
            isPrime[j] = false;
        }
    }
    return isPrime;
}

bool isprime(const vector<bool>& isPrime,ll a){
    return a >= 2 and isPrime[a];
}

int main(){
    const ll M = 100000000;
    vector<bool> isPrime = sieve(M);
    ll ret = 0;
    ll maxi = 0;
    for(ll a=-999;a<=999;a++){
        for(ll b=-999;b<=999;b++){
            for(ll n=0;isprime(isPrime,n*n+a*n+b);n++){
                if(n > maxi){
                    maxi = n;
                    ret = a*b;
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}
