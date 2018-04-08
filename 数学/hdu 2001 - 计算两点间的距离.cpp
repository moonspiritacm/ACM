#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    double x1,y1,x2,y2;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF) {
        double tmp=pow(x2-x1,2)+pow(y2-y1,2);
        tmp=sqrt(tmp);
        printf("%.2lf\n",tmp);
    }
    return 0;
}
