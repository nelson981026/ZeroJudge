#include <stdio.h>
int main(void) {
    int n, x, y, tx, ty, w = 1, tw, l = 0, r = 0, b = 0;
    scanf("%d", &n);
    scanf("%d%d", &x, &y);
    for (int i = 0; i < n - 1; ++i) {
        tx = x;
        ty = y;
        tw = w;
        scanf("%d%d", &x, &y);
        if (x > tx)
            w = 1;
        else if (y > ty)
            w = 2;
        else if (x < tx)
            w = 3;
        else if (y < ty)
            w = 4;
        else
            w = 0;
        switch ((w - tw + 100) % 4) {
            case 1:
                l++;
                break;
            case 2:
                b++;
                break;
            case 3:
                r++;
                break;
        }
    }
    printf("%d %d %d", l, r, b);
    return 0;
}
