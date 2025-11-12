#include <stdio.h>
#include <string.h>
int main(void) {
    char cou[10][10][10];
    memset(cou, 0, sizeof(cou));
    int n, x = 0, y = 0, z = 0;
    scanf("%d ", &n);
    char temp[15];
    for (int i = 0; i < n; ++i) {
        scanf("%s", temp);
        int so = 0, se = 0;
        for (int x = 0; x < 12; ++x) {
            temp[x] -= '0';
            if (x % 2) {
                se += temp[x];
            } else {
                so += temp[x];
            }
        }
        if ((so + 3 * se + temp[12] - '0') % 10 == 0) {
            cou[temp[0]][temp[1]][temp[2]]++;
        }
    }
    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            for (int c = 0; c < 10; ++c) {
                if (cou[a][b][c] > cou[x][y][z]) {
                    x = a;
                    y = b;
                    z = c;
                }
            }
        }
    }
    printf("%d%d%d %d\n", x, y, z, cou[x][y][z]);
    return 0;
}
