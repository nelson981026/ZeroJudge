#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, cnt = 0, ind = 0;
    cin >> n >> m;
    vector<vector<int>> bd(n);
    vector<int> clr(n);
    for (auto &v : bd) {
        v.resize(3);
        cin >> v[1] >> v[0] >> v[2];
        v[1]--;
        v[2]--;
        if (clr[v[1]] == 0)
            cnt++;
        clr[v[1]]++;
    }
    sort(bd.begin(), bd.end());
    for (int i = 1; i <= m; ++i) {
        while (ind < n && bd[ind][0] == i) {
            clr[bd[ind][1]]--;
            if (clr[bd[ind][1]] == 0)
                cnt--;
            if (clr[bd[ind][2]] == 0)
                cnt++;
            clr[bd[ind][2]]++;
            ind++;
        }
        cout << cnt << endl;
    }
    return 0;
}