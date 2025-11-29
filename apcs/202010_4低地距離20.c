#include <stdio.h>
#include <string.h>
int main(void) {
    int n, i, k, x;
    unsigned long long count = 0;
    scanf("%d", &n);
    int arr[n * 2];
    char temp[n + 1];
    for (i = 0; i < 2 * n; ++i) {
        scanf("%d", &arr[i]);
    }
    memset(temp, 0, sizeof(temp));
    for (i = 0; i < 2 * n; ++i) {
        temp[arr[i]]++;
        for (k = n; k > arr[i]; --k) {
            count += temp[k] % 2;
        }
    }
    printf("%d\n", count);
    return 0;
}