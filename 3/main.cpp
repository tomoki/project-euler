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

const ll M = 600851475143l;
const ll P = 1000000;
vector<ll> primes;
bool isPrime[P] = {false};
void sieve(){
    for(int i=2;i<P;i++) isPrime[i] = true;
    for(int i=2;i*i < P;i++){
        if(!isPrime[i]) continue;
        for(int j=i*i;j<P;j+=i) isPrime[j] = false;
    }
    for(int i=2;i<P;i++) if(isPrime[i]) primes.push_back(i);
}
int main(){
    sieve();
    ll ret = 2;
    for(int i=0;i<primes.size();i++){
        if(M % primes[i] == 0)
            ret = primes[i];
    }
    cout << ret << endl;
    return 0;
}
