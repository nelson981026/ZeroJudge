#include <bits/stdc++.h>
using namespace std;
const int arrX[6] = {0, 25, 10, 5, 4, -10};
const int arrY[6] = {0, 10, 20, 15, 20, -15};
int main() {
    int n, x = 0, y = 0, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp < 6) {
            x += arrX[tmp];
            y += arrY[tmp];
        } else if (tmp == 6) {
            x -= 35;
            y = 0;
        } else {
            x = 0;
            y = (y * 9) / 10;
        }
        if (x < 0) {
            x = 0;
        } else if (x > 100) {
            x = 0;
            y = 0;
        }
    }
    cout << y << endl;
    return 0;
}