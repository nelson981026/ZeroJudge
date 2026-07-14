#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w, cnt;
    char c;
    cin >> h >> w;
    vector<string> img(h);
    for (int x = 0; x < h; ++x) {
        cin >> img[x];
    }
    int top = 0, bot = h - 1, left = 0, right = w - 1;
    while (top <= bot) {
        cnt = 0;
        for (char c : img[top]) {
            cnt += (c == '#');
        }
        if (cnt == 0)
            top++;
        else
            break;
    }
    while (bot >= top) {
        cnt = 0;
        for (char c : img[bot]) {
            cnt += (c == '#');
        }
        if (cnt == 0)
            bot--;
        else
            break;
    }
    while (left <= right) {
        cnt = 0;
        for (int i = 0; i < h; ++i) {
            cnt += (img[i][left] == '#');
        }
        if (cnt == 0)
            left++;
        else
            break;
    }
    while (right >= left) {
        cnt = 0;
        for (int i = 0; i < h; ++i) {
            cnt += (img[i][right] == '#');
        }
        if (cnt == 0)
            right--;
        else
            break;
    }
    for (int x = top; x <= bot; ++x) {
        for (int y = left; y <= right; ++y) {
            cout << img[x][y];
        }
        cout << endl;
    }
    return 0;
}