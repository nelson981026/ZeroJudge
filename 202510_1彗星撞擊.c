#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? (a) : (b);
}
int min(int a, int b) {
    return (a < b) ? (a) : (b);
}
int main(void) {
    int r, c, h, k, m;
    scanf("%d%d%d", &r, &c, &h);
    int dino[r][c], high[r][c];
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            dino[x][y] = 0;
            high[x][y] = h;
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        dino[x][y]++;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int a, b, s, d, flag = 0;
        scanf("%d%d%d%d", &a, &b, &s, &d);
        for (int x = max(0, a - s / 2); x <= min(r - 1, a + s / 2); ++x) {
            for (int y = max(0, b - s / 2); y <= min(c - 1, b + s / 2); ++y) {
                flag += dino[x][y];
                dino[x][y] = 0;
            }
        }
        if (flag == 0) {
            for (int x = max(0, a - s / 2); x <= min(r - 1, a + s / 2); ++x) {
                for (int y = max(0, b - s / 2); y <= min(c - 1, b + s / 2); ++y) {
                    high[x][y] -= d;
                }
            }
        }
    }

    int mina = 1 << 30, maxa = -(1 << 30), cou = 0;
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (high[x][y] > maxa)
                maxa = high[x][y];
            if (high[x][y] < mina)
                mina = high[x][y];
            cou += dino[x][y];
        }
    }

    printf("%d %d %d\n", maxa, mina, cou);
    return 0;
}
