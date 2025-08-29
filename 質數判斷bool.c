#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  unsigned long long *arr=malloc(sizeof(unsigned long long)*33554432),i,k;
  memset(arr,0,sizeof(unsigned long long)*33554432);
  arr[0]|=((unsigned long long)1<<(0));
  arr[0]|=((unsigned long long)1<<(1));
  for(i=2;i*i<=2147483647;++i){
    if(arr[i/64]&((unsigned long long)1<<(i%64))){
      continue;
    }
    for(k=i*i;k<=2147483647;k+=i){
      arr[k/64]|=((unsigned long long)1<<(k%64));
    }
  }
  printf("F\n");
  int n;
  while(scanf("%d",&n)!=EOF){
    if(arr[n/64]&((unsigned long long)1<<(n%64))){
      printf("非質數\n");
    }
    else{
      printf("質數\n");
    }
  }
  return 0;
}
