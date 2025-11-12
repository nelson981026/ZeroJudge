#include <limits.h>
#include <stdio.h>
int main(void) {
    int a1, b1, c1, a2, b2, c2, n;
    long long int maxa = LONG_MIN, temp;
    scanf("%d%d%d", &a1, &b1, &c1);
    scanf("%d%d%d", &a2, &b2, &c2);
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        temp = a1 * i * i + b1 * i + c1 + a2 * (n - i) * (n - i) + b2 * (n - i) + c2;
        if (temp > maxa) {
            maxa = temp;
        }
    }
    printf("%lld", maxa);
    return 0;
}