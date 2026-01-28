#include <bits/stdc++.h>
using namespace std;
long long sum = 0;
int abs(int a) {
    return (a > 0) ? a : -a;
}
void t(int f) {
    int temp;
    scanf("%d", &temp);
    if (!temp) {
        return;
    }
    sum += abs(f - temp);
    t(temp);
    if (temp % 2) {
        t(temp);
    }
    t(temp);
    return;
}
int main() {
    int temp;
    scanf("%d", &temp);
    t(temp);
    if (temp % 2) {
        t(temp);
    }
    t(temp);
    printf("%lld\n", sum);
    return 0;
}
