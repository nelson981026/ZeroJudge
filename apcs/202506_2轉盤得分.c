#include <stdio.h>
#include <string.h>
void skip(char *arr, int len, int det) {
    det += len * 100;
    det %= len;
    int i;
    char temp[len];
    memset(temp, 0, sizeof(temp));
    for (i = 0; i < len; ++i) {
        temp[i] = arr[i];
    }
    for (i = 0; i < det; ++i) {
        arr[i] = temp[len - det + i];
    }
    for (i = 0; i < len - det; ++i) {
        arr[det + i] = temp[i];
    }
    return;
}

int main() {
    int m, n, k, score = 0, det, x, y, z, maxa;
    scanf("%d %d %d ", &m, &n, &k);
    char arr[m][n + 1];
    int count[n][26];

    memset(arr, '\0', sizeof(arr));
    for (x = 0; x < m; ++x) {
        scanf("%s", &arr[x][0]);
    }

    for (x = 0; x < k; x++) {
        memset(count, 0, sizeof(count));
        for (y = 0; y < m; ++y) {
            scanf("%d", &det);
            skip(arr[y], n, det);
            for (z = 0; z < n; ++z) {
                count[z][arr[y][z] - 'a']++;
            }
        }

        for (y = 0; y < n; ++y) {
            maxa = 0;
            for (z = 0; z < 26; ++z) {
                if (count[y][z] > maxa) {
                    maxa = count[y][z];
                }
            }
            score += maxa;
        }
    }

    printf("%d\n", score);
    return 0;
}