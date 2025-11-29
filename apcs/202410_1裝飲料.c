#include <stdio.h>
#define MINA(a, b) ((a) < (b) ? (a) : (b))
int main() {
    int n, w1, w2, h1, h2, dv1, dv2, deltaH, i, maxa = 0;
    scanf("%d%d%d%d%d", &n, &w1, &w2, &h1, &h2);
    int v[n], v1 = w1 * w1 * h1, v2 = w2 * w2 * h2;
    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; ++i) {
        dv1 = MINA(v[i], v1);
        v[i] -= dv1;
        v1 -= dv1;
        dv2 = MINA(v[i], v2);
        v[i] -= dv2;
        v2 -= dv2;
        deltaH = dv1 / (w1 * w1) + dv2 / (w2 * w2);
        // printf("\tdv1=%d,dv2=%d,dH=%d+%d=%d\n",dv1,dv2,dv1/(w1*w1),dv2/(w2*w2),deltaH);
        if (deltaH > maxa) {
            maxa = deltaH;
        }
    }
    printf("%d\n", maxa);
    return 0;
}