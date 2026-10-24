// o079
#include <bits/stdc++.h>
#define PLI pair<long long, int>
#define MP make_pair
using namespace std;
inline int detla(int x) {
    return x % 2 ? 1 : -1;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<vector<PLI>> dpFront(8001), dpBack(8001);
    dpFront[4000].emplace_back(MP(0, -1));
    dpBack[4000].emplace_back(MP(0, n));
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cnt += detla(a[i]);
        sum += a[i];
        dpFront[cnt + 4000].emplace_back(MP(sum, i));
        // printf("F:(%lld,%d)\n",sum,i);
    }
    cnt = 0, sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        cnt -= detla(a[i]);
        ;
        sum += a[i];
        dpBack[cnt + 4000].emplace_back(MP(sum, i));
        // printf("B:(%lld,%d)\n",sum,i);
    }
    long long maxa = 0;
    for (int i = 0; i < 8001; ++i) {
        for (PLI x : dpFront[i]) {
            for (PLI y : dpBack[i]) {
                if (x.first + y.first <= k && x.second < y.second) {
                    maxa = max(maxa, x.first + y.first);
                }
            }
        }
    }
    cout << maxa << endl;
    return 0;
}