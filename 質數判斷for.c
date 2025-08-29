#include <stdio.h>
int main(void) {
  int n,i;
  while(scanf("%d",&n)!=EOF){
    if(n<2){
      printf("獶借计\n");
    }
    else if(n%2){
      for(i=3;i*i<=n;i+=2){
        if(!(n%i)){
          printf("獶");
          break;
        }
      }
      printf("借计\n");
    }
    else{
      if(n>2){
        printf("獶借计\n");
      }
      else{
        printf("借计\n");
      }
    }
  }
  return 0;
}
