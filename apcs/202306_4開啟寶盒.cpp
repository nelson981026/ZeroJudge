// k734
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, t, cnt = 0;
    cin >> n >> m >> k >> t;
    vector<bool> have(m, 0);
    vector<vector<int>> help(m);
    vector<int> helped(n);
    queue<int> flag;
    for (int i = 0; i < t; ++i) {
        int tmp;
        cin >> tmp;
        have[tmp] = 1;
    }
    vector<vector<int>> need(n, vector<int>(k)), receive(n, vector<int>(k));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < k; ++y) {
            cin >> need[x][y];
            help[need[x][y]].emplace_back(x);
            helped[x] += have[need[x][y]];
        }
        if (helped[x] == k) {
            flag.push(x);
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < k; ++y) {
            cin >> receive[x][y];
        }
    }
    while (!flag.empty()) {
        int x = flag.front();
        for (int i = 0; i < k; ++i) {
            if (!have[receive[x][i]]) {
                have[receive[x][i]] = 1;
                for (int y : help[receive[x][i]]) {
                    helped[y]++;
                    if (helped[y] == k) {
                        flag.push(y);
                    }
                }
            }
        }
        flag.pop();
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}