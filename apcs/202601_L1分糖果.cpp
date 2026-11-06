#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, sum = 0, tmp, maxa = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        sum += tmp;
        maxa = max(maxa, tmp);
    }
    sum -= maxa;
    cout << maxa << " " << sum / m << " ";
    if ((sum % m) * 2 > m) {
        cout << m - (sum % m) << endl;
    } else {
        cout << (sum % m) << endl;
    }
    return 0;
}