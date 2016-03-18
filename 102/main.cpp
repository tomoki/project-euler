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


// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(point a,point b){
    return real(conj(a)*b);
}

// 外積 (cross product) : |a×b| = |a||b|sinΘ
double cross(point a,point b){
    return imag(conj(a)*b);
}

int ccw(point a,point b,point c){
    b -= a;c -= a;
    if(cross(b,c) > 0) return +1;    // counter clockwise
    if(cross(b,c) < 0) return -1;    // clockwise
    if(dot(b,c) < 0) return +2;      // c -- a -- b
    if(norm(b) < norm(c)) return -2; // a -- b -- c
    return 0;
}


bool is_inner_point_vertex(vector<point> ps,point a){
    int cc = ccw(ps[0],ps[1],a);
    if(not(cc == 1 or cc == -1)) return false;
    for(int i=0;i<ps.size();i++){
        if(cc != ccw(ps[i],ps[(i+1)%ps.size()],a)) return false;
    }
    return true;
}

int main(){
    char c;
    point origin;
    int cnt = 0;
    for(int i=0;i<1000;i++){
        vector<point> ps(3);
        cin >> ps[0].real() >> c >> ps[0].imag() >> c
            >> ps[1].real() >> c >> ps[1].imag() >> c
            >> ps[2].real() >> c >> ps[2].imag();
        if(is_inner_point_vertex(ps,origin)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
