#include <stdio.h>
int main() {
    int a, ca, b, cb, n, temp, cou = 0;
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i < n; ++i) {
        ca = 0, cb = 0;
        while (1) {
            scanf("%d", &temp);
            if (!temp) {
                break;
            }
            if (temp == a)
                ca++;
            else if (temp == -a)
                ca--;
            else if (temp == b)
                cb++;
            else if (temp == -b)
                cb--;
        }
        if (ca > 0 && cb > 0) {
            cou++;
        }
    }
    printf("%d\n", cou);
    return 0;
}