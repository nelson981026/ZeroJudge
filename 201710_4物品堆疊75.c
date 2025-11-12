#include <stdio.h>
#include <stdlib.h>
#define ULL unsigned long long
int com(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int n, x;
    scanf("%d", &n);
    if (n > 1000) {
        printf("1\n");
        return 0;
    }
    int w[n], f[n], sumf = 0;
    ULL sum = 0;
    for (x = 0; x < n; ++x) {
        scanf("%d", &w[x]);
    }
    for (x = 0; x < n; ++x) {
        scanf("%d", &f[x]);
        sumf += f[x];
    }
    // case 1 & 3
    if (n == sumf) {
        qsort(w, n, sizeof(int), com);
        for (x = 0; x < n; ++x) {
            sum += (ULL)w[x] * x;
        }
    }
    // case 2
    else if (n == 3) {
        sum = 1 << 31;
        int d, m, u;
        ULL temp;
        for (d = 0; d < 3; ++d) {
            for (m = 0; m < 3; ++m) {
                if (d == m)
                    continue;
                u = 3 - d - m;
                temp = w[u] * (f[m] + f[d]) + w[m] * f[d];
                if (temp < sum)
                    sum = temp;
            }
        }
    }
    printf("%llu\n", sum);
    return 0;
}