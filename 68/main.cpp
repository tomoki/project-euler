#include <iostream>
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
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

#define all(c) c.begin(),c.end()
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

typedef long long ll;
typedef complex<double> point;
typedef vector<int> vi;

template<class T>
inline int len(const T& t){
    return t.size();
}

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

vector<vi> c = {
    {0,1,2},
    {3,2,4},
    {5,4,6},
    {7,6,8},
    {9,8,1}
};

vector<int> d = {
    0,1,2,3,2,4,5,4,6,7,6,8,9,8,1
};

int main(){
    vector<int> p(10);
    rep(i,10) p[i] = i+1;

    vector<string> ans;
    do{
        vector<int> h;
        rep(i,len(c)){
            int s = 0;
            rep(j,len(c[i])){
                s += p[c[i][j]];
            }
            h.push_back(s);
        }
        bool ok = all_of(all(h),[h](int x){return x==h[0];});
        vector<int> top = {p[0],p[3],p[5],p[7],p[9]};
        if(p[0] == *min_element(all(top)) and ok){
            stringstream ss;
            rep(i,d.size()){
                ss << p[d[i]];
            }
            string s = ss.str();
            if(len(s) == 16){
                // cerr << s << endl;
                // cerr << p << endl;
                ans.push_back(s);
            }
        }
    }while(next_permutation(all(p)));
    sort(all(ans));
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}
