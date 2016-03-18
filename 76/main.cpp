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

ll solve(int rest,int maxi,vector<vector<ll> > &memo){
    if(memo[rest][maxi] != -1) return memo[rest][maxi];
    if(rest == 0) return memo[rest][maxi]=1;
    ll ret = 0;
    for(int i=1;i<=min(maxi,rest);i++){
        ret += solve(rest-i,i,memo);
    }
    return memo[rest][maxi]=ret;
}

int main(){
    vector<vector<ll> > memo(101,vector<ll>(101,-1));
    cout << solve(100,99,memo) << endl;
    return 0;
}
