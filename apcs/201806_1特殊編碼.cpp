#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned int n,a[4];
    char ret[2][2][2][2];
    ret[0][1][0][1]='A';
    ret[0][1][1][1]='B';
    ret[0][0][1][0]='C';
    ret[1][1][0][1]='D';
    ret[1][0][0][0]='E';
    ret[1][1][0][0]='F';
    while(scanf("%u",&n)!=EOF){
        for(unsigned int i=0;i<n;++i){
            scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
            printf("%c",ret[a[0]][a[1]][a[2]][a[3]]);
        }
        printf("\n");
    }
    return 0;
}