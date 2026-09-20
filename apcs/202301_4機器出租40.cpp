#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
int main() {
    int n, k, maxa = 0;
    cin >> n >> k;
    vector<PII> time(n);
    vector<int> best(n + 1, 1 << 30);
    best[0] = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &time[i].second);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &time[i].first);
    }
    sort(time.begin(), time.end());
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(best.begin(), best.end(), time[i].second) - best.begin();
        best[x] = min(best[x], time[i].first);
        maxa = max(maxa, x);
    }
    cout << maxa << "\n";
}