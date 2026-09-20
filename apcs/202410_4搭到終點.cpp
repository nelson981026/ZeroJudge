#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
int n, m, p;
vector<PII> bus;
vector<long long> ind, dp, pfs;
inline long long mod(long long x) {
    return ((x % p) + p) % p;
}
int main() {
    cin >> n >> m >> p;
    bus.resize(n);
    ind.resize(n + 1);
    dp.resize(n + 1);
    pfs.resize(n + 2);
    ind[0] = 0;
    dp[0] = 1;
    pfs[0] = 0;
    pfs[1] = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &bus[i].second);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &bus[i].first);
    }
    sort(bus.begin(), bus.end());
    for (int i = 0; i < n; ++i) {
        ind[i + 1] = bus[i].first;
    }
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(ind.begin(), ind.end(), bus[i].second) - ind.begin();
        int r = lower_bound(ind.begin(), ind.end(), bus[i].first) - ind.begin() - 1;
        dp[i + 1] = mod(pfs[r + 1] - pfs[l]);
        pfs[i + 2] = mod(pfs[i + 1] + dp[i + 1]);
        // printf("\tFor i=%d, l=%d->%d,r=%d->%d, dp[%d]=%d, pfs[%d]=%d\n"
        //     ,i,bus[i].second,l,bus[i].first,r,i+1,dp[i+1],i+2,pfs[i+2]);
    }
    long long ret = 0;
    for (int i = 0; i < n + 1; ++i) {
        if (ind[i] == m) {
            ret = mod(ret + dp[i]);
            // printf("\ti=%d, ret+=%d\n",i,dp[i]);
        }
    }
    cout << ret << "\n";
}