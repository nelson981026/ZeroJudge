#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, n, lc = 0, li, rc = 0, ri, t;
    cin >> x >> n;
    li = x;
    ri = x;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t > x) {
            rc++;
            if (t > ri) {
                ri = t;
            }
        } else {
            lc++;
            if (t < li) {
                li = t;
            }
        }
    }
    if (lc > rc) {
        cout << lc << " " << li;
    } else {
        cout << rc << " " << ri;
    }
    return 0;
}