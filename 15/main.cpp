#include <iostream>
#include <cstdio>
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
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define rep(i,n) for(int i=0;i<(n);i++)
#define tr(it,container) for(typeof(container.begin()) it = container.begin(); \
                                                  it != container.end(); ++it)
#define mp(a,b) make_pair((a),(b))
#define eq ==

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

// →↑←↓
const int dy[] = {0,-1,0,1};
const int dx[] = {1,0,-1,0};

const double EPS = 1e-9;
const int days[]     = {31,28,31,30,31,30,31,31,30,31,30,31};
const int daysleap[] = {31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    int n = 20,m = 20;
    n++,m++;
    vector<vector<ll> > grid(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        grid[0][i] = 1;
    }
    for(int i=0;i<m;i++){
        grid[i][0] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    cout << grid.back().back() << endl;
    return 0;
}
