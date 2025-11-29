#include <stdio.h>
#include <string.h>

int class(char temp) {
    if (temp <= 'Z' && temp >= 'A')
        return 1;
    else if (temp <= 'z' && temp >= 'a')
        return -1;
    else
        return 0;
}

int main() {
    int k;
    scanf("%d\n", &k);
    char arr[100000];
    memset(arr, 0, sizeof(arr));
    char temp;
    int i = 0, x, y, sta, cou, max = 0, flag, p;

    while (scanf("%c", &temp) != EOF) {
        if (temp == '\n')
            break;
        arr[i++] = class(temp);
    }

    for (x = 0; x < i; ++x) {
        sta = arr[x];
        cou = 0;
        flag = 1;
        p = x;
        while (flag) {
            for (y = p; y < p + k; ++y) {
                if (arr[y] != sta) {
                    flag = 0;
                }
            }
            if (flag) {
                p += k;
                cou += k;
                sta *= -1;
                if (cou > max)
                    max = cou;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}