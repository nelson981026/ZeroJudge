#include <stdio.h>

int findMin(int *arr, int n) {
    int i, mi = -1;
    for (i = 0; i < n; ++i) {
        if (arr[i] && mi == -1) {
            mi = i;
        } else if (arr[i] && arr[i] < arr[mi]) {
            mi = i;
        }
    }
    if (mi == -1) {
        return 0;
    } else {
        return mi;
    }
}

int main() {
    int n, t, i, minIndex;
    unsigned long long sum = 0;
    scanf("%d %d", &n, &t);
    int arr[n];
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    minIndex = findMin(arr, n);
    while (arr[minIndex] && arr[minIndex] <= t) {
        sum += arr[minIndex];
        for (i = minIndex + 1; i < n; ++i) {
            if (arr[i]) {
                arr[i] += arr[minIndex];
                break;
            }
        }
        arr[minIndex] = 0;
        minIndex = findMin(arr, n);
    }
    printf("%llu", sum);
    return 0;
}