#include <stdio.h>
#include <stdlib.h>
struct dice {
    int f, b, u, d, l, r;
};

struct dice *create() {
    struct dice *ret = malloc(sizeof(struct dice));
    ret->f = 4;
    ret->b = 3;
    ret->u = 1;
    ret->d = 6;
    ret->r = 2;
    ret->l = 5;
    return ret;
}

void front(struct dice *di) {
    int t = di->f;
    di->f = di->u;
    di->u = di->b;
    di->b = di->d;
    di->d = t;
}

void right(struct dice *di) {
    int t = di->u;
    di->u = di->l;
    di->l = di->d;
    di->d = di->r;
    di->r = t;
}

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    struct dice *arr[n], *temp;
    for (int i = 0; i < n; ++i) {
        arr[i] = create();
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (b == -2) {
            front(arr[a]);
        } else if (b == -3) {
            right(arr[a]);
        } else {
            temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]->u);
    }
    return 0;
}