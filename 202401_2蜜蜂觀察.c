#include <stdio.h>
#include <string.h>
int main(void) {
    int m, n, k, x, y, i, act, count = 0;
    scanf("%d %d %d", &m, &n, &k);
    char arr[m][n + 1], actx[6] = {-1, 0, 1, 1, 0, -1}, acty[6] = {0, 1, 1, 0, -1, -1}, cou[256];
    memset(cou, 0, sizeof(cou));
    for (x = 0; x < m; x++) {
        scanf("%s", &arr[x]);
    }
    x = m - 1, y = 0;
    for (i = 0; i < k; i++) {
        scanf("%d", &act);
        if ((x + actx[act]) >= 0 && (x + actx[act]) < m && (y + acty[act]) >= 0 &&
            (y + acty[act]) < n) {
            x += actx[act];
            y += acty[act];
        }
        cou[arr[x][y]] = 1;
        printf("%c", arr[x][y]);
    }
    printf("\n");
    for (i = 0; i < 256; i++) {
        count += cou[i];
    }
    printf("%d", count);
    return 0;
}
