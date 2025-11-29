#include <stdio.h>
// dic -> 0right 1down 2left 3up
void turn(int *x) {
    *x = (*x + 1) % 4;
}
int main() {
    int m, n, k, a, b;
    int pts = 0, cou = 0;
    int x, y, dic = 0;
    scanf("%d%d%d%d%d", &m, &n, &k, &a, &b);
    int map[m][n];
    for (x = 0; x < m; ++x) {
        for (y = 0; y < n; ++y) {
            scanf("%d", &map[x][y]);
        }
    }
    while (map[a][b] != 0) {
        pts += map[a][b];
        map[a][b]--;
        cou++;
        if (pts % k == 0) {
            turn(&dic);
        }
    f:
        switch (dic) {
            case 0:
                if (b + 1 >= n || map[a][b + 1] == -1) {
                    turn(&dic);
                    goto f;
                }
                b++;
                break;
            case 1:
                if (a + 1 >= m || map[a + 1][b] == -1) {
                    turn(&dic);
                    goto f;
                }
                a++;
                break;
            case 2:
                if (b - 1 < 0 || map[a][b - 1] == -1) {
                    turn(&dic);
                    goto f;
                }
                b--;
                break;
            case 3:
                if (a - 1 < 0 || map[a - 1][b] == -1) {
                    turn(&dic);
                    goto f;
                }
                a--;
                break;
        }
    }
    printf("%d\n", cou);
    return 0;
}
