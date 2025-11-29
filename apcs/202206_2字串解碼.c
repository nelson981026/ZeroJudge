#include <stdio.h>
#include <string.h>
void swap(signed char *s) {
    int l = strlen(s), i;
    char t;
    for (i = 0; i < l / 2; ++i) {
        t = s[i];
        s[i] = s[l / 2 + l % 2 + i];
        s[l / 2 + l % 2 + i] = t;
    }
    return;
}
int main() {
    int m, n, x, y, cf, cb;
    scanf("%d %d ", &m, &n);
    signed char e[m][n + 1];
    signed char s[n + 1], f[n + 1], b[n + 1];
    for (x = 0; x < m; ++x) {
        scanf("%s ", &e[x]);
        for (y = 0; y < n; ++y) {
            e[x][y] -= '0';
        }
    }
    scanf("%s", s);

    for (x = m - 1; x >= 0; --x) {
        memset(f, 0, sizeof(f));
        memset(b, 0, sizeof(b));
        cf = 0;
        cb = 0;
        for (y = n - 1; y >= 0; --y) {
            if (e[x][y]) {
                // back
                b[cb++] = s[y];
            } else {
                // front
                f[cf++] = s[y];
            }
        }
        for (y = 0; y < cf; ++y) {
            s[y] = f[cf - y - 1];
        }
        strcpy(&s[y], b);
        int cou = 0;
        for (y = 0; y < n; ++y) {
            cou += e[x][y];
        }
        if (cou % 2) {
            swap(s);
        }
    }
    printf("%s", s);
    return 0;
}
