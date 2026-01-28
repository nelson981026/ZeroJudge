#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n, sum = 0, t;
    cin >> a >> b >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t % (a + b) >= a) {
            sum += (a + b) - (t % (a + b));
        }
    }
    cout << sum;
    return 0;
}