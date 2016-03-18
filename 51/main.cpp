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

int to_i(string s){
    stringstream ss;
    int ret;
    ss << s;
    ss >> ret;
    return ret;
}

vector<bool> sieve(const int M){
    vector<bool> isPrime(M);
    for(int i=2;i<M;i++) isPrime[i] = true;
    for(int i=2;i*i < M;i++){
        if(not isPrime[i]) continue;
        for(int j=i*i;j<M;j+=i){
            isPrime[j] = false;
        }
    }
    return isPrime;
}

ll lpow(ll x,ll n){
    if(n==0) return 1;
    ll ret = lpow(x * x,n/2);
    if(n%2==1)  ret = ret * x;
    return ret;
}

int main(){
    int N = 1000000;
    int ret = 10000000;
    vector<bool> isPrime = sieve(N);
    for(int i=0;i<N;i++){
        if(not isPrime[i]) continue;
        string s = to_s(i);
        for(ll mask=0;mask<pow(2,s.size());mask++){
            int cnt = 0;
            for(int r='0';r<='9';r++){
                string a = s;
                for(int k=0;k<s.size();k++){
                    if(mask & (1 << k)){
                        a[k] = r;
                    }
                }
                if(a[0] != '0' and isPrime[to_i(a)]) cnt++;
            }
            if(cnt == 8){
                cerr << i << endl;
                ret = min(ret,i);
            }
        }
    }
    cout << ret << endl;
    return 0;
}
