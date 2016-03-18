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
    const int M = 1000010;
    vector<bool> isPrime = sieve(M);

    int ret = 0;
    for(int i=1;i<1000000;i++){
        string s;
        {
            stringstream ss;
            ss << i;
            ss >> s;
        }
        bool ok = true;
        for(int j=0;j<=s.length();j++){
            rotate(s.begin(),s.begin()+1,s.end());
            int n;
            stringstream ss;
            ss << s;
            ss >> n;
            ok = ok and isPrime[n];
        }
        if(ok){
            ret++;
            cerr << i << endl;
        }
    }
    cout << ret << endl;
    return 0;
}
