#include <stdio.h>
void cy(int arr[], char on[], int i) {
    if (on[i] == 0)
        return;
    else {
        on[i] = 0;
        cy(arr, on, arr[i]);
    }
}

int main(void) {
    int n, c = 0, re = 0;
    scanf("%d", &n);
    int arr[n];
    char on[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        on[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (on[i]) {
            cy(arr, on, i);
            re++;
        }
    }
    printf("%d", re);
    return 0;
}