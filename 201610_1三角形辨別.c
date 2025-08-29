#include <stdio.h>
/*c294三角形辨別

內容
三角形除了是最基本的多邊形外，亦可進一步細分為鈍角三形、直角三角形及銳角三角形。若給定三個線段的長度，透過下列公式運算，即可得知此三線段能否構成三角形，亦可判斷是直角、銳角和鈍角三角形。
提示：若a、b、c為三個線段的邊長，且c為最大值，則
若 a+b ≦ c　　　　　，三線段無法構成三角形
若 a×a+b×b ＜ c×c　　，三線段構成鈍角三角形(Obtuse triangle)
若 a×a+b×b ＝ c×c　　，,三線段構成直角三角形(Right triangle)
若 a×a+b×b ＞ c×c　　，三線段構成銳角三角形(Acute triangle)
請設計程式以讀入三個線段的長度判斷並輸出此三線段可否構成三角形？若可，判斷 並輸出其所屬三角形類型。

輸入說明
輸入僅一行包含三正整數，三正整數皆小於 30,001，兩數之間有一空白。

輸出說明
輸出共有兩行，第一行由小而大印出此三正整數，兩字之間以一個空白格間格，最後 一個數字後不應有空白；第二行輸出三角形的類型：
若無法構成三角形時輸出「No」；
若構成鈍角三形時輸出「Obtuse」；
若直角三形時輸出「Right」；
若銳角三形時輸出「Acute」。*/

int main(void) {
  int a,b,c,t;
  scanf("%d %d %d",&a,&b,&c);
  if(a>b){    t=a;    a=b;    b=t;}
  if(a>c){    t=a;    a=c;    c=t;}
  if(b>c){    t=b;    b=c;    c=t;}
  printf("%d %d %d",a,b,c);
  if(a+b<=c)    printf("\nNo");
  else if (a*a+b*b>c*c)    printf("\nObtuse");
  else if (a*a+b*b==c*c)    printf("\nRight");
  else if (a*a+b*b<c*c)    printf("\nAcute");
  return 0;
}