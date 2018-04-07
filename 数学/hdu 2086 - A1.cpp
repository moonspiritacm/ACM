#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    int n;
    double a0,a1,ax,sum,tmp;
    while(scanf("%d",&n)!=EOF) {
        sum=0.0;
        scanf("%lf %lf",&a0,&ax);
        for(int i=0; i<n; i++) {
            scanf("%lf",&tmp);
            sum+=2*(n-i)*tmp;
        }
        a1=(ax+n*a0-sum)/(n+1);
        printf("%.2lf\n",a1);
    }
    return 0;
}
