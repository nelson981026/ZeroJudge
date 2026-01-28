#include <bits/stdc++.h>
using namespace std;
bool win(int f, int t) {
    return ((f == 0 && t == 2) || (f == 5 && t == 0) || (f == 2 && t == 5));
}
// 2 0 5
int main() {
    int f, n, t, l = -1;
    cin >> f >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        cout << f << " ";
        if (f == t) {
            if (l == t) {
                switch (t) {
                    case 2:
                        f = 0;
                        break;
                    case 0:
                        f = 5;
                        break;
                    case 5:
                        f = 2;
                        break;
                }
            } else {
                f = t;
            }
            l = t;
        } else if (win(f, t)) {
            printf(": Won at round %d", i + 1);
            return 0;
        } else {
            printf(": Lost at round %d", i + 1);
            return 0;
        }
    }
    printf(": Drew at round %d", n);
    return 0;
}