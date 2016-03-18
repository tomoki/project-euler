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

#include <omp.h>

using namespace std;

#define all(c) c.begin(),c.end()

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

const double EPS = 1e-9;
const long long million = 1000000;

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

template<typename T>
int to_i(T s){
    stringstream ss;
    int ret;
    ss << s;
    ss >> ret;
    return ret;
}

bool is_ok(const int &n){
    string rev = to_s(n);
    reverse(all(rev));
    if(rev[0] == '0') return false;
    string added = to_s(n+to_i(rev));
    for(int i=0;i<added.size();i++){
        if((added[i] - '0') % 2 == 0) return false;
    }
    return true;
}

int main(){
    int N = 1000000000;
    int ret = 0;
    int cnt = 0;
#pragma omp parallel for
    for(int i=1;i<N;i++){
        if(cnt % 100000 == 0){
            cerr << (1.0 * cnt / N) * 100 << "%" << endl;
        }
        if(is_ok(i)) ret++;
        cnt++;
    }
    cout << ret << endl;
    return 0;
}
