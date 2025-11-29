#include <stdio.h>
int abs(int a) {
    return (a > 0) ? (a) : (-a);
}
int d(int a[2], int b[2]) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
int main() {
    int x, t[2], a[2], min = 10000, max = 0;
    scanf("%d", &x);
    scanf("%d %d", &a[0], &a[1]);
    for (int i = 1; i < x; ++i) {
        t[0] = a[0];
        t[1] = a[1];
        scanf("%d %d", &a[0], &a[1]);
        if (d(a, t) > max) {
            max = d(a, t);
        }
        if (d(a, t) < min) {
            min = d(a, t);
        }
    }
    printf("%d %d\n", max, min);
}
