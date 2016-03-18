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
    vector<int> m;
    for(int i=1;i<=9;i++) m.push_back(i);

    set<int> s;
    do{
        // 1 2 | 3 4 5 | 6 7 8 9 
        for(int i=1;i<9;i++){
            for(int j=1;j<9-i;j++){
                int a=0,b=0,c=0;
                for(int ai=0;ai<i;ai++){
                    a *= 10;
                    a += m[ai];
                }
                for(int bi=i;bi<i+j;bi++){
                    b *= 10;
                    b += m[bi];
                }
                for(int ci=i+j;ci<9;ci++){
                    c *= 10;
                    c += m[ci];
                }
                //cerr << a << " " << b << " " << c << endl;
                if(a * b == c){
                    s.insert(c);
                }
            }
        }
    }while(next_permutation(all(m)));
    cout << accumulate(all(s),0) << endl;
    return 0;
}
