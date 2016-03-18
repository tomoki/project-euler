#include <stdio.h>
#include <omp.h>

int gcd(int a,int b){
    return b==0 ? a : gcd(b,a%b);
}

int main(){
    int N = 1000000;
    double ret = 0;
    int reti = 0;
    int per=0;
#pragma omp parallel for
    for(int a=2;a<=N;a++){
        //printf("\r%lf%%",1.0*per/N);
        int cnt = 0;
        for(int b=1;b<a;b++){
            if(gcd(a,b) == 1) cnt++;
        }
        double nex = 1.0 * a / cnt;
        if(ret < nex){
            ret = nex;
            reti = a;
            printf("%d %lf\n",reti,ret);
        }
    }
    printf("%d\n",reti);
    return 0;
}
