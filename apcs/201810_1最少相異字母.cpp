#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; ++i) {
        vector<bool> f(26);
        int cnt = 0;
        cin >> v[i].second;
        for (auto c : v[i].second) {
            if (f[c - 'A'] == 0) {
                cnt++;
                f[c - 'A'] = 1;
            }
        }
        v[i].first = cnt;
    }
    sort(v.begin(), v.end());
    cout << v[0].second;
    return 0;
}