#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
int main() {
    int n, cnt = 0;
    cin >> n;
    vector<PII> v(n);
    for (auto &p : v) {
        cin >> p.F >> p.S;
    }
    sort(v.begin(), v.end());
    int mini = v[0].S;
    for (auto p : v) {
        mini = min(mini, p.S);
        if (mini == p.S) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}