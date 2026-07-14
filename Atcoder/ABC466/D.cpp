#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<bool> row(n, 0), col(n, 0);
    vector<PII> op(m);
    for (auto &p : op) {
        cin >> p.F >> p.S;
        p.F--;
        p.S--;
    }
    reverse(op.begin(), op.end());
    for (auto p : op) {
        if ((!row[p.F]) && (!col[p.S])) {
            cnt++;
        }
        row[p.F] = 1;
        col[p.S] = 1;
    }
    cout << cnt;
    return 0;
}