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
    vector<ll> efibs;
    efibs.push_back(1);
    efibs.push_back(2);
    for(int i=2;;i++){
        ll next = efibs[i-1] + efibs[i-2];
        if(next > 4000000) break;
        efibs.push_back(next);
    }
    ll ret = 0;
    for(int i=0;i<efibs.size();i++){
        cerr << efibs[i] << endl;
        if(efibs[i] % 2 ==0)
            ret += efibs[i];
    }
    cout << ret << endl;
    return 0;
}
