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
    vector<int> vec;
    for(int i=0;i<10;i++) vec.push_back(i);
    vector<string> perms;
    do{
        string s = "";
        for(int i=0;i<vec.size();i++){
            s += vec[i] + '0';
        }
        perms.push_back(s);
    }while(next_permutation(all(vec)));
    sort(all(perms));
    cout << perms[1000000-1] << endl;

    return 0;
}
