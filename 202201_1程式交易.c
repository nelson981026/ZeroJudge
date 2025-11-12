#include <stdio.h>
int main() {
    int n, d, i, mon = 0, x, y, have = 1;
    scanf("%d %d %d", &n, &d, &x);
    for (i = 1; i < n; i++) {
        scanf("%d", &y);
        if (have == 1 && y >= (x + d)) {
            have = 0;
            mon += y - x;
            x = y;
        }
        if (have == 0 && y <= (x - d)) {
            have = 1;
            x = y;
        }
    }
    printf("%d\n", mon);
    return 0;
}
