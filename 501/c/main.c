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

ll ret = 0;
ll solve(ll n){
    /* ll ret = 0; */
    ret = 0;
//#pragma omp parallel for reduction(+:ret)
    for(ll i=1;i<=n;i++){
        if(count_divisors(i) == 8){
            ret++;
        }
        printf("%f%%\n",1.0*i/n);
    }
    return ret;
}


int main(){
    ll n = 0;
    scanf("%lld",&n);
    printf("%lld\n",solve(n));

    return 0;
}
