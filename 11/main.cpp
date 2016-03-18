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
const int dy[] = {0,-1,0,1,-1,-1,1,1};
const int dx[] = {1,0,-1,0,-1,1,-1,1};

const double EPS = 1e-9;
const int days[]     = {31,28,31,30,31,30,31,31,30,31,30,31};
const int daysleap[] = {31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    int n = 20;
    int m = 20;
    vector<vector<int> > grid(n+2,vector<int>(m+2,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
        }
    }
    int ret = 0;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=m;x++){
            for(int k=0;k<8;k++){
                int now = 1;
                for(int c=0;c<4;c++){
                    cerr << y+dy[k]*c << " " << x+dx[k]*c << endl;
                    if(grid[y+dy[k]*c][x+dx[k]*c] == -1){
                        now = -1;
                        break;
                    }
                    now *= grid[y+dy[k]*c][x+dx[k]*c];
                }
                if(now != -1){
                    ret = max(ret,now);
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}
