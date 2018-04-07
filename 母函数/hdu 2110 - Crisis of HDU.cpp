#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[10001],b[10001];
int v[101],n1[101],n2[101];

/*************************************************
Function:       GenerateFunc(int N,int P)
Description:    生成函数系数计算
Input:          int N : 相乘的因子个数
                int P : 待求的最大指数
Output:         void
Return:         void
Others:         修改的全局变量 a[] b[]
                只读的全局变量 v[] n1[] n2[]
*************************************************/
void GenerateFunc(int N,int P) {
    memset(a,0,sizeof(a));
    a[0]=1;
    for(int i=0; i<N; i++) {
        memset(b,0,sizeof(b));
        for(int j=n1[i]; j<=n2[i]&&j*v[i]<=P; j++) {
            for(int k=0; k+j*v[i]<=P; k++) {
                b[k+j*v[i]]+=a[k];
                b[k+j*v[i]]%=10000;
            }
        }
        memcpy(a,b,sizeof(b));
    }
}

int main() {
    int n,p;
    memset(n1,0,sizeof(n1));
    scanf("%d",&n);
    while(n!=0) {
        p=0;
        for(int i=0; i<n; i++) {
            scanf("%d %d",&v[i],&n2[i]);
            p+=v[i]*n2[i];
        }
        if(p%3!=0) {
            printf("sorry\n");
            scanf("%d",&n);
            continue;
        }
        p/=3;
        GenerateFunc(n,p);
        if(a[p]==0) {
            printf("sorry\n");
        } else {
            printf("%d\n",a[p]);
        }
        scanf("%d",&n);
    }
}
