#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[1001],b[1001];
int v[27],n1[27],n2[27];

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
    int N,sum;
    for(int i=0; i<26; i++) {
        v[i]=i+1;
    }
    memset(n1,0,sizeof(n1));
    scanf("%d",&N);
    while(N--) {
        sum=0;
        for(int i=0; i<26; i++) {
            scanf("%d",&n2[i]);
        }
        GenerateFunc(26,50);
        for(int i=0; i<=50; i++) {
            sum+=a[i];
        }
        printf("%d\n",sum-1);
    }
}
