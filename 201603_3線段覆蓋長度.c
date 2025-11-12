#include <stdio.h>
#include <string.h>
int main(void) {
    int n, i, min = 10000001, max = -1, cou = 0;
    scanf("%d", &n);
    int temp[n][2];
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &temp[i][0], &temp[i][1]);
        if (temp[i][0] < min) {
            min = temp[i][0];
        }
        if (temp[i][1] > max) {
            max = temp[i][1];
        }
    }
    char arr[max - min + 1];
    memset(arr, 0, sizeof(arr));
    for (i = 0; i < n; ++i) {
        if (temp[i][1] > temp[i][0]) {
            memset(&arr[temp[i][0] - min], 1, sizeof(char) * (temp[i][1] - temp[i][0]));
        }
    }
    for (i = 0; i < max - min + 1; ++i) {
        cou += arr[i];
    }
    printf("%d\n", cou);
    return 0;
}
