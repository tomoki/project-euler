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

const int P = 8;
const int pound[P] = {1,2,5,10,20,50,100,200};

int solve(int rest,int r){
    if(r == P) return rest == 0;
    int ret = 0;
    for(int i=0;pound[r]*i<=rest;i++){
        ret += solve(rest-pound[r]*i,r+1);
    }
    return ret;
}

int main(){
    cout << solve(200,0) << endl;
    return 0;
}
