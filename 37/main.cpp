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
    const int M = 1000000;
    vector<bool> isPrime = sieve(M+1);
    vector<int> oks;
    for(int r=10;r<M and oks.size() < 12;r++){
        string s;
        stringstream ss;
        ss << r;
        ss >> s;

        bool ok = true;
        for(int i=1;i<=s.length();i++){
            string n = s.substr(0,i);
            stringstream ns;
            ns << n;
            int ni;
            ns >> ni;
            ok = ok and isPrime[ni];
        }
        for(int i=0;i<s.length();i++){
            string n = s.substr(i);
            stringstream ns;
            ns << n;
            int ni;
            ns >> ni;
            ok = ok and isPrime[ni];
        }
        if(ok) {
            cerr << r << endl;
            oks.push_back(r);
        }
    }
    cout << "result:" << accumulate(all(oks),0) << endl;
    return 0;
}
