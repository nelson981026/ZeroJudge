#include <stdio.h>
int main(void) {
  int n,i;
  while(scanf("%d",&n)!=EOF){
    if(n<2){
      printf("�D���\n");
    }
    else if(n%2){
      for(i=3;i*i<=n;i+=2){
        if(!(n%i)){
          printf("�D");
          break;
        }
      }
      printf("���\n");
    }
    else{
      if(n>2){
        printf("�D���\n");
      }
      else{
        printf("���\n");
      }
    }
  }
  return 0;
}
