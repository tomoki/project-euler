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

ll to_dfact(ll x,const vector<ll>&memo){
    string s = to_s(x);
    ll ret = 0;
    for(int i=0;i<s.length();i++){
        int d = to_i(s[i]);
        ret += memo[d];
    }
    return ret;
}

ll loop_cnt(ll x,const vector<ll>&memo){
    set<ll> alr;
    while(alr.find(x) == alr.end()){
        alr.insert(x);
        x = to_dfact(x,memo);
    }
    return alr.size();
}

int main(){
    vector<ll> facts(10);
    facts[0] = 1;
    for(int i=1;i<facts.size();i++){
        facts[i] = i * facts[i-1];
    }
    int ret = 0;
    for(int i=1;i<million;i++){
        ll cnt = loop_cnt(i,facts);
        if(cnt == 60){
            cerr << i << endl;
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}
