#include <stdio.h>
int main() {
    int ind = 0, k, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &k, &x1, &y1, &x2, &y2);
    while (k > 0) {
        ind += k;
        if (!(ind % x1)) {
            k -= y1;
        }
        if (!(ind % x2)) {
            k -= y2;
        }
    }
    printf("%d\n", ind);
    return 0;
}
