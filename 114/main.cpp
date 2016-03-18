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

ll solve(int rest,int red,int least_red,vector<vector<ll> >& memo){
    if(memo[rest][red] != -1) return memo[rest][red];
    if(rest == 0){
        if(1 <= red and red < least_red) return memo[rest][red]=0;
        else return memo[rest][red]=1;
    }else if(1 <= red and red < least_red){
        return memo[rest][red]=solve(rest-1,red+1,least_red,memo);
    }else{
        return memo[rest][red]=(solve(rest-1,0,least_red,memo) + solve(rest-1,red+1,least_red,memo));
    }
}

int main(){
    ll least_red = 50;
    for(int st=0;;st++){
        vector<vector<ll> > memo(st+1,vector<ll>(st+1,-1));
        ll s = solve(st,0,least_red,memo);
        if(s > 1000000){
            cout << st << endl;
            break;
        }
    }

    return 0;
}
