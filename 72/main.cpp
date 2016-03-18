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

int main(){
    const int N = 1000000;
    //const int N = 8;
    bool used[N+1] = {false};
    ll cnt = 0;
    for(int d=N;d>=1;d--){
        cerr << d << " " << cnt << endl;
        if(used[d]) continue;

        for(int n=1;n<d;n++){
            if(d % n == 0){
                if(used[d/n]) cnt--;
                used[d/n] = true;
            }
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
