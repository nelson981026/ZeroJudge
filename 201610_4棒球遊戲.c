#include <stdio.h>
#include <string.h>

int main(void) {
    char arr[9][5] = {-1}, k[4];
    memset(arr, -1, sizeof(arr));
    int t, d;
    for (int m = 0; m < 9; m++) {
        scanf("%d ", &t);
        for (int n = 0; n < t; n++) {
            scanf("%3s", k);
            switch (k[0]) {
                case '1':
                    arr[m][n] = 1;
                    break;
                case '2':
                    arr[m][n] = 2;
                    break;
                case '3':
                    arr[m][n] = 3;
                    break;
                case 'H':
                    arr[m][n] = 4;
                    break;
                default:
                    arr[m][n] = 0;
                    break;
            }
        }
    }
    scanf("%d", &d);
    char base[3] = {0}, out = 0, outsum = 0, point = 0, hitter = 0, round = 0;
    while (outsum < d) {
        while (out < 3) {
            switch (arr[hitter][round]) {
                case 0:
                    out++;
                    outsum++;
                    break;
                case 1:
                    point += base[2];
                    base[2] = base[1];
                    base[1] = base[0];
                    base[0] = 1;
                    break;
                case 2:
                    point += (base[1] + base[2]);
                    base[2] = base[0];
                    base[1] = 1;
                    base[0] = 0;
                    break;
                case 3:
                    point += (base[0] + base[1] + base[2]);
                    base[2] = 1;
                    base[1] = 0;
                    base[0] = 0;
                    break;
                case 4:
                    point += (base[0] + base[1] + base[2] + 1);
                    base[2] = 0;
                    base[1] = 0;
                    base[0] = 0;
                    break;
            }
            if (d == outsum)
                break;
            hitter++;
            if (hitter == 9) {
                round++;
                hitter = 0;
            }
        }
        base[2] = 0;
        base[1] = 0;
        base[0] = 0;
        out = 0;
    }
    printf("%d", point);
    return 0;
}
