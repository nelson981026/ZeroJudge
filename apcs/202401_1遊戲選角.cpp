#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    cout << a[1].first << " " << a[1].second;
    return 0;
}