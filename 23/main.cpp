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

int main(){
    int N = 30000;
    vector<ll> sum_of_divisors(N);
    for(int i=1;i<N;i++){
        for(int j=2;j*i < N;j++){
            sum_of_divisors[j*i] += i;
        }
    }
    vector<ll> abundent;
    for(int i=1;i<N;i++){
        if(sum_of_divisors[i] > i) abundent.push_back(i);
    }
    set<ll> not_ok;
    for(int i=0;i<abundent.size();i++){
        for(int j=0;j<abundent.size();j++){
            not_ok.insert(abundent[i]+abundent[j]);
        }
    }
    ll ret = 0;
    for(int i=0;i<N;i++){
        if(not_ok.find(i) == not_ok.end()) ret += i;
    }
    cout << ret << endl;
    return 0;
}
