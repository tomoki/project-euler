#include <stdio.h>
#include <omp.h>
#include <math.h>
typedef long long ll;

ll sqrt_ceil(ll n){
    return (ll)(sqrt(n + 0.1));
}

ll count_divisors(ll n){
    ll u  = sqrt_ceil(n);
    ll k  = 0;
    int l = (u*u == n)?-1:0;
    for(ll i=1;i<=u;i++){
        if(n % i == 0) k++;
    }
    return 2*k+l;
}

const ll 
ll solve(ll n){
    int ret = 0;
    for(ll i=1;
}
