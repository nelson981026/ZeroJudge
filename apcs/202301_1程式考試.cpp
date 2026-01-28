#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    int score = -k;
    pair<int, int> tmp, best = {0, -2};
    for (int i = 0; i < k; ++i) {
        cin >> tmp.first >> tmp.second;
        if (tmp.second > best.second) {
            best = tmp;
        }
        if (tmp.second < 0) {
            score -= 2;
        }
    }
    score += best.second;
    cout << (score > 0 ? score : 0) << " " << best.first;
    return 0;
}