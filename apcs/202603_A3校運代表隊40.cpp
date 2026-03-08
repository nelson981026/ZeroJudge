#include <bits/stdc++.h>
using namespace std;
int n, m, r, k, t;
vector<int> pl;
vector<vector<int>> s;
void sch(vector<bool> g, vector<int> r, int i) {
    if (r.size() == k) {
        s.emplace_back(r);
        return;
    }
    if (i >= m) {
        return;
    }
    sch(g, r, i + 1);
    if (g[pl[i]] == 0) {
        g[pl[i]] = 1;
        r.emplace_back(i);
        sch(g, r, i + 1);
    }
}
int main() {
    cin >> n >> m >> r >> k >> t;
    if (r > 1) {
        for (int i = 0; i < k; ++i) {
            printf("%d ", 2 * i + 1);
        }
        return 0;
    }
    pl.resize(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &pl[i]);
        pl[i]--;
    }
    vector<bool> g(n);
    vector<int> r;
    sch(g, r, 0);
    sort(s.begin(), s.end());
    for (auto x : s[t - 1]) {
        printf("%d ", x + 1);
    }
    return 0;
}