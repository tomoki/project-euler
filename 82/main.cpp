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

struct State{
    int r,c;
    ll s;
    State(int r,int c,ll s) : r(r),c(c),s(s) {};
};
bool operator<(const State& left,const State& right){
    return left.s < right.s;
}

bool operator>(const State& left,const State& right){
    return left.s > right.s;
}

int main(){
    int N = 80;
    vector<vector<ll> > matrix(N+2,vector<ll>(N+2,10000000000ll));
    vector<vector<char> > alr(N+2,vector<char>(N+2,true));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> matrix[i+1][j+1];
            alr[i+1][j+1] = false;
            if(j != N-1){
                char c;
                cin >> c;
            }
        }
    }

    cerr << matrix << endl;
    priority_queue<State,vector<State>,greater<State> > que;
    for(int i=1;i<=N;i++) que.push(State(i,1,matrix[i][1]));
    while(not que.empty()){
        int r = que.top().r;
        int c = que.top().c;
        ll s = que.top().s;
        que.pop();
        if(alr[r][c]) continue;
        alr[r][c] = true;
        if(c == N){
            cout << s << endl;
            break;
        }else{
            que.push(State(r+1,c,s+matrix[r+1][c]));
            que.push(State(r,c+1,s+matrix[r][c+1]));
            que.push(State(r-1,c,s+matrix[r-1][c]));
        }
    }
    return 0;
}
