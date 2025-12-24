#include <algorithm>
#include <iostream>
using namespace std;

int cou(int m, int n, int *ind) {
    int i = 0, c = 1;
    for (int x = 1; x < n; ++x) {
        if (ind[x] > ind[i] + m) {
            c++;
            i = x;
        }
    }
    return c;
}

int main() {
    int n, k;
    cin >> n >> k;
    int ind[n];
    for (int i = 0; i < n; ++i)
        cin >> ind[i];
    sort(ind, ind + n);

    int l = 0, r = ind[n - 1] - ind[0], m;
    while (l + 1 < r) {
        m = (l + r) / 2;
        if (cou(m, n, ind) <= k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}
