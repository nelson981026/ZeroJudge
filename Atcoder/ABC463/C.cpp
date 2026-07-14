#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
int cmp(PII a, PII b) {
    return a.F > b.F;
}
int main() {
    int n, q, ind = 0, m = -1;
    cin >> n;
    vector<PII> ps(n);
    for (auto &p : ps) {
        cin >> p.S >> p.F;
    }
    sort(ps.begin(), ps.end(), cmp);
    cin >> q;
    vector<int> t(q);
    map<int, int, greater<>> mp;
    for (int i = 0; i < q; ++i) {
        cin >> t[i];
        mp[t[i]] = -1;
    }
    for (auto &x : mp) {
        while (ind < ps.size() && ps[ind].F > x.F) {
            m = max(m, ps[ind++].S);
        }
        x.S = m;
    }
    for (int i = 0; i < q; ++i) {
        cout << mp[t[i]] << endl;
    }
    return 0;
}