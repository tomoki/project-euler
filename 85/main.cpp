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

ll cnt(ll w,ll h){
    ll ret = 0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            ret += (w-i+1) * (h-j+1);
        }
    }
    return ret;
}

int main(){
    ll N = 100;
    ll ret = 0;
    ll want = 2000000;
    ll goodi = 1000000000;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            ll diff = abs(want-cnt(i,j));
            if(diff < goodi){
                goodi = diff;
                cout << i * j << endl;
            }
        }
    }
    return 0;
}
