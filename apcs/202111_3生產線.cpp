#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, l, r, w;
    long long sum = 0;
    cin >> n >> m;
    vector<int> work(n + 1), time(n);
    for (int i = 0; i < m; ++i) {
        cin >> l >> r >> w;
        work[l - 1] += w;
        work[r] -= w;
    }
    for (int i = 1; i < n + 1; ++i) {
        work[i] += work[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> time[i];
    }
    sort(work.begin(), work.end());
    sort(time.begin(), time.end());
    reverse(work.begin(), work.end());
    for (int i = 0; i < n; ++i) {
        sum += work[i] * time[i];
    }
    cout << sum;
    return 0;
}