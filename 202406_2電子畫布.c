#include <stdio.h>
#include <string.h>
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
int main(void) {
    int h, w, n, r, c, t, x, a, b, i;
    scanf("%d %d %d", &h, &w, &n);
    unsigned int arr[h][w];
    memset(arr, 0, sizeof(arr));

    for (i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &r, &c, &t, &x);
        for (a = 0; a < h; ++a) {
            for (b = 0; b < w; ++b) {
                if (ABS(r - a) + ABS(c - b) <= t) {
                    arr[a][b] += x;
                }
            }
        }
    }

    for (a = 0; a < h; ++a) {
        for (b = 0; b < w; ++b) {
            printf("%d ", arr[a][b]);
        }
        printf("\n");
    }
    return 0;
}
