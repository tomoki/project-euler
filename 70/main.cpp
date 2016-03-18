// compile in C++11. use -std=c++11.
#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

// this require C++11
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

#define all(c) c.begin(),c.end()
#define repeat(i,n) for(int i=0;i<static_cast<int>(n);i++)
#define debug(x) #x << "=" << (x)
#define dump(x) cerr << debug(x) << " (L:" << __LINE__ << ")"<< endl

using ll = long long;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& vec){
    os << "[";
    for(const auto& v : vec){
        os << v << ",";
    }
    os << "]";
    return os;
}

template<typename T>
string to_s(const T& a){
    stringstream ss;
    ss << a;
    return ss.str();
}

// nと互いに素な数の個数
// n (1-1/p1) ... (1-1/pn)
template<typename T>
T totient(T n){
    if(n == 0) return 0;
    T ans = n;
    for(T x=2;x*x <= n;x++){
        if(n % x == 0){
            ans -= ans/x;
            while(n % x == 0) n /= x;
        }
    }
    if(n > 1){
        ans -= ans/n;
    }
    return ans;
}

bool is_permutation(ll a,ll b){
    string as,bs;
    as = to_s(a);
    bs = to_s(b);
    sort(all(as));
    sort(all(bs));
    return as == bs;
}


int solve(){
    int ret = -1;
    double min_ratio = 100000;
    for(ll n=2;n<10000000;n++){
        ll t = totient(n);
        double ratio = 1.0*n/t;
        if(is_permutation(n,t) and min_ratio > ratio){
            ret = n;
            min_ratio = ratio;
        }
    }
    return ret;
}

int main(){
    cout << solve() << endl;
    return 0;
}
