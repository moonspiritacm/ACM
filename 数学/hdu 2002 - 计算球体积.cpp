#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define PI 3.1415927

using namespace std;

int main() {
    double r;
    while(scanf("%lf",&r)!=EOF) {
        double tmp=PI*pow(r,3)*4/3;
        printf("%.3lf\n",tmp);
    }
    return 0;
}
