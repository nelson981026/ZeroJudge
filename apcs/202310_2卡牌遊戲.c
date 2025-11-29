#include <stdio.h>
int main(void) {
    int m, n, cou = 0, a, b, i, tx, ix, ty, iy;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    for (a = 0; a < m; ++a) {
        for (b = 0; b < n; ++b) {
            scanf("%d", &arr[a][b]);
        }
    }
    for (i = 0; i < m * n; ++i) {
        for (a = 0; a < m; ++a) {
            tx = -1;
            for (b = 0; b < n; ++b) {
                //
                if (tx == -1) {
                    tx = arr[a][b];
                    ix = b;
                } else {
                    if (arr[a][b] == -1) {
                        continue;
                    } else if (arr[a][b] == tx) {
                        cou += tx;
                        arr[a][b] = -1;
                        arr[a][ix] = -1;
                        tx = -1;
                    } else {
                        tx = arr[a][b];
                        ix = b;
                    }
                }
                //
            }
        }
        for (b = 0; b < n; ++b) {
            ty = -1;
            for (a = 0; a < m; a++) {
                //
                if (ty == -1) {
                    ty = arr[a][b];
                    iy = a;
                } else {
                    if (arr[a][b] == -1) {
                        continue;
                    } else if (arr[a][b] == ty) {
                        cou += ty;
                        arr[a][b] = -1;
                        arr[iy][b] = -1;
                        ty = -1;
                    } else {
                        ty = arr[a][b];
                        iy = a;
                    }
                }
                //
            }
        }
    }
    printf("%d\n", cou);
    return 0;
}
