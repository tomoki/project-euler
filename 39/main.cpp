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

int main(){
    int ret = 0;
    int reti = 0;
    for(int p=1;p<=1000;p++){
        int now = 0;
        for(int a=1;a<p;a++){
            for(int b=a;b<p-a-1;b++){
                //a <= b <= c
                int c = p - a - b;
                if(a + b > c and a * a + b * b == c * c){
                    now++;
                }
                if(ret < now){
                    ret = now;
                    reti = p;
                }
            }
        }
    }
    cout << reti << endl;
    return 0;
}
