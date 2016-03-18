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

int main(){
    const int N = 300000;
    vector<bool> isPrime = sieve(N);
    vector<int> are;
    for(int i=0;i<N;i++){
        int cnt = 0;
        for(int j=0;j<N;j++){
            if(isPrime[j] and i % j == 0){
                cnt++;
            }
        }
        are.push_back(cnt);
    }

    for(int i=0;i<N-3;i++){
        bool ok = true;
        for(int j=0;j<4;j++){
            ok = ok and are[i+j] == 4;
        }
        if(ok){
            cout << i << endl;
        }
    }
    return 0;
}
