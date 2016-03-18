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

template<typename T>
string to_s(T v){
    stringstream ss;
    ss << v;
    return ss.str();
}

ll to_i(string s){
    stringstream ss;
    ll ret;
    ss << s;
    ss >> ret;
    return ret;
}


vector<bool> sieve(const ll M){
    vector<bool> isPrime(M);
    for(ll i=2;i<M;i++) isPrime[i] = true;
    for(ll i=2;i*i < M;i++){
        if(not isPrime[i]) continue;
        for(ll j=i*i;j<M;j+=i){
            isPrime[j] = false;
        }
    }
    return isPrime;
}

int main(){
    vector<bool> isPrime = sieve(10000000001ll);
    ll ret = 0;
    for(int n=1;n<=9;n++){
        string s;
        for(ll c='1';c<'1'+n;c++){
            s += c;
        }
        do{
            ll a = to_i(s);
            if(isPrime[a]){
                cerr << a << endl;
                ret = max(ret,a);
            }
        }while(next_permutation(all(s)));
    }
    cout << ret << endl;
    return 0;
}
