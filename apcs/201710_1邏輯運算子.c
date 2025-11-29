#include <stdio.h>
/*
輸入說明
輸入只有一行，共三個整數值，整數間以一個空白隔開。
第一個整數代表 a，第二個整數代表 b，這兩數均為非負的整數。
第三個整數代表邏輯運算的結果，只會是 0 或 1。

輸出說明
輸出可能得到指定結果的運算，若有多個，輸出順序為AND、OR、XOR，每個可能的運算單獨輸出一行，每行結尾皆有換行。
若不可能得到指定結果，輸出IMPOSSIBLE。
（注意輸出時所有英文字母均為大寫字母。）*/

int main(void) {
    int a, b, c, i = 0;
    scanf("%d %d %d", &a, &b, &c);
    if ((a && b) == c) {
        printf("AND\n");
        i++;
    }
    if ((a || b) == c) {
        printf("OR\n");
        i++;
    }
    if ((((a || b) == 1) && ((a && b) == 0)) == c) {
        printf("XOR\n");
        i++;
    }
    if (i == 0)
        printf("IMPOSSIBLE\n");
    return 0;
}