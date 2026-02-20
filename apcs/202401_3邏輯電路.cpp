#include <bits/stdc++.h>
using namespace std;
int p, q, r, m;
vector<int> lg;
vector<pair<int, int>> port; // first for value, second for step
vector<vector<int>> line;
int getb(int id) {
    if (id < p) {
        return port[id].first;
    } else if (id < p + q) {
        if (port[id].first > -1) {
            return port[id].first;
        } else {
            int x = getb(line[id][0]), y;
            if (lg[id - p] != 4)
                y = getb(line[id][1]);
            switch (lg[id - p]) {
                case 1: // AND
                    port[id].first = x && y;
                    port[id].second = max(port[line[id][0]].second, port[line[id][1]].second) + 1;
                    return port[id].first;
                case 2: // OR
                    port[id].first = x || y;
                    port[id].second = max(port[line[id][0]].second, port[line[id][1]].second) + 1;
                    return port[id].first;
                case 3: // XOR
                    port[id].first = x != y;
                    port[id].second = max(port[line[id][0]].second, port[line[id][1]].second) + 1;
                    return port[id].first;
                case 4: // NOT
                    port[id].first = !x;
                    port[id].second = (port[line[id][0]].second) + 1;
                    return port[id].first;
            }
        }
    } else {
        int ret = getb(line[id][0]);
        port[id].second = port[line[id][0]].second;
        return ret;
    }
    return 0;
}
int main() {
    int x, y, maxa = 0;
    cin >> p >> q >> r >> m;
    lg.resize(q);
    port.resize(p + q + r);
    line.resize(p + q + r);

    for (int i = 0; i < p; ++i) {
        cin >> port[i].first;
        port[i].second = 0;
    }
    for (int i = 0; i < q; ++i) {
        cin >> lg[i];
        port[p + i].first = -1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        line[y - 1].emplace_back(x - 1);
    }

    for (int i = 0; i < r; ++i) {
        port[p + q + i].first = getb(p + q + i);
        if (port[p + q + i].second > maxa) {
            maxa = port[p + q + i].second;
        }
    }

    cout << maxa << endl;
    for (int i = 0; i < r; ++i) {
        cout << port[p + q + i].first << " ";
    }
    return 0;
}