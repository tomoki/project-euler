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
    int height;
    cin >> height;
    vector<vector<int> > T(height,vector<int>(height));
    for(int i=0;i<height;i++){
        for(int j=0;j<=i;j++){
            cin >> T[i][j];
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<height;j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int> > DP(height,vector<int>(height));
    DP[0][0] = T[0][0];
    for(int i=0;i<height-1;i++){
        for(int j=0;j<=i;j++){
            DP[i+1][j] = max(DP[i+1][j],DP[i][j]+T[i+1][j]);
            DP[i+1][j+1] = max(DP[i+1][j+1],DP[i][j]+T[i+1][j+1]);
        }
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<height;j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    int ret = 0;
    for(int i=0;i<height;i++){
        ret = max(ret,DP.back()[i]);
    }
    cout << ret << endl;
    return 0;
}
