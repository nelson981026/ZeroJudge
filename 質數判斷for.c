#include <stdio.h>
int main(void) {
  int n,i,f;
  while(scanf("%d",&n)!=EOF){
    if(n<2){
      printf("It's not a prime!!!\n");
    }
    else if(n%2){
      f=0;
      for(i=3;i*i<=n;i+=2){
        if(!(n%i)){
          printf("It's not a prime!!!\n");
          f=1;
          break;
        }
      }
      if(f==0){
        printf("It's a prime!!!\n");
      }
    }
    else{
      if(n>2){
        printf("It's not a prime!!!\n");
      }
      else{
        printf("It's a prime!!!\n");
      }
    }
  }
  return 0;
}
