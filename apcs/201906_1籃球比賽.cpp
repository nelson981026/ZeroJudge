#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0, b = 0, t, aw = 0;
    for (int x = 0; x < 2; ++x) {
        a = 0, b = 0;
        for (int i = 0; i < 4; ++i) {
            cin >> t;
            a += t;
        }
        for (int i = 0; i < 4; ++i) {
            cin >> t;
            b += t;
        }
        cout << a << ":" << b << endl;
        if (a > b) {
            aw++;
        }
    }
    switch (aw) {
        case 0:
            cout << "Lose";
            break;
        case 1:
            cout << "Tie";
            break;
        case 2:
            cout << "Win";
            break;
    }
    return 0;
}