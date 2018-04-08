#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    char ch[3];
    while(scanf("%s",ch)!=EOF) {
        sort(ch,ch+3,less<char>());
        printf("%c %c %c\n",ch[0],ch[1],ch[2]);
    }
    return 0;
}
