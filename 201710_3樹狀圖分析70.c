#include <stdio.h>
#include <string.h>

int h(int i, int arr[][3], int high[]) {
    if (arr[i][0] == -1) {
        return 0;
    }
    int maxa = 0;
    for (int x = 0; x < 3; ++x) {
        if (arr[i][x] == -1) {
            break;
        }
        if (high[arr[i][x]] == -1) {
            high[arr[i][x]] = h(arr[i][x], arr, high);
        }
        if (high[arr[i][x]] > maxa) {
            maxa = high[arr[i][x]];
        }
    }
    return maxa + 1;
}

int main() {
    int n, x, y, k;
    scanf("%d", &n);
    int arr[n][3], high[n], parent[n], sum = 0;

    for (x = 0; x < n; ++x) {
        high[x] = -1;
        parent[x] = 0;
    }

    for (x = 0; x < n; ++x) {
        scanf("%d", &k);
        for (y = 0; y < k; ++y) {
            scanf("%d", &arr[x][y]);
            arr[x][y]--;
            parent[arr[x][y]]++;
        }
        for (y = k; y < 3; ++y) {
            arr[x][y] = -1;
        }
    }

    for (x = 0; x < n; ++x) {
        if (!parent[x]) {
            printf("%d\n", x + 1);
            break;
        }
    }
    for (x = 0; x < n; ++x) {
        if (high[x] == -1) {
            high[x] = h(x, arr, high);
        }
        sum += high[x];
    }
    printf("%d\n", sum);
    return 0;
}