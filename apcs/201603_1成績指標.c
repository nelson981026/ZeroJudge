#include <stdio.h>
/*b964成績指標

內容
一次考試中，於所有及格學生中獲取最低分數者最為幸運，反之，於所有不及格同學中，獲取最高分數者，可以說是最為不幸，而此二種分數，可以視為成績指標。
請你設計一支程式，讀入全班成績(人數不固定)，請對所有分數進行排序，並分別找出不及格中最高分數，以及及格中最低分數。
當找不到最低及格分數，表示對於本次考試而言，這是一個不幸之班級，此時請你印出「worst
case」；反之，當找不到最高不及格分數時，請你印出「best case」。 ( 註：假設及格分數為 60 )。

輸入說明
第一行輸入學生人數，第二行為各學生分數(0~100 間)，分數與分數之間以一個空白間格。
學生人數為 1~20 的整數。

輸出說明
輸出三行。
第一行由小而大印出所有成績，兩數字之間以一個空白間格，最後一個數字後無空白；
第二行印出最高不及格分數，如果全數及格時，於此行印出 best case ；
第三行印出最低及格分數，如果全數不及格時，於此行印出 worst case 。*/

int main(void) {
    int n;
    scanf("%d", &n);
    char arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int t;
    for (int x = 0; x < n - 1; x++) {
        for (int y = 0; y < n - x - 1; y++) {
            if (arr[y] > arr[y + 1]) {
                t = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = t;
            }
        }
    }

    printf("%d", arr[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", arr[i]);
    t = 0;

    if (n == 1) {
        if (arr[0] >= 60)
            printf("\nbest case\n%d", arr[0]);
        else
            printf("\n%d\nworst case", arr[0]);
        return 0;
    }

    if (arr[0] >= 60) {
        printf("\nbest case\n%d", arr[0]);
        return 0;
    }
    if (arr[n - 1] < 60) {
        printf("\n%d\nworst case", arr[n - 1]);
        return 0;
    }

    while (arr[t] < 60 && t < n - 1)
        t++;
    printf("\n%d", arr[t - 1]);
    printf("\n%d", arr[t]);
    return 0;
}