#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n, cou = 1, max = 0, i, temp = 0, now = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        temp = now;
        scanf("%d", &now);
        if (now < temp) {
            cou++;
        } else {
            if (cou > max) {
                max = cou;
            }
            cou = 1;
        }
    }
    if (cou > max) {
        max = cou;
    }
    printf("%d\n", max);
    return 0;
}
