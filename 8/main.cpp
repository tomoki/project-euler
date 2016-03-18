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
    string input;
    {
        string s;
        while(cin >> s){
            input+=s;
        }
    }
    int maxpro = -1;
    for(int i=0;i<input.size()-5;i++){
        int product = 1;
        for(int j=0;j<5;j++){
            product *= input[i+j]-'0';
            maxpro = max(maxpro,product);
        }
    }
    cout << maxpro << endl;
    return 0;
}
