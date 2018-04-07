#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[1001],b[1001];
int v[9],n1[9],n2[9];

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
            }
        }
        memcpy(a,b,sizeof(b));
    }
}

int main() {
    int T;
    memset(n1,0,sizeof(n1));
    scanf("%d",&T);
    while(T--) {
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0; i<k; i++) {
            scanf("%d %d",&v[i],&n2[i]);
        }
        GenerateFunc(k,n);
        printf("%d\n",a[n]);
    }
}
