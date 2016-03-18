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


vector<bool> sieve(const int M){
    vector<bool> isPrime(M);
    for(int i=2;i<M;i++) isPrime[i] = true;
    for(int i=2;i*i < M;i++){
        if(not isPrime[i]) continue;
        for(int j=i*i;j<M;j+=i){
            isPrime[j] = false;
        }
    }
    return isPrime;
}

int main(){
    ll M = 1000000000;
    vector<bool> isprime = sieve(M);

    ll primes = 0;
    ll total = 0;
    ll now = 1;
    ll up = 2;

    for(int i=0;i<20000;i++){
        for(int j=0;j<4;j++){
            now += up;
            total++;
            if(isprime[now]) primes++;
        }
        cerr << 1.0 * primes / total << endl;
        if(1.0 * primes / total <= 0.1){
            cout << 1 + up << endl;
            break;
        }
        up += 2;
    }
    return 0;
}
