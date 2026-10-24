// j125
#include <bits/stdc++.h>
#define PII pair<int, int>
#define MP make_pair
using namespace std;
inline int abs(int n) {
    return n > 0 ? n : -n;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> mp(n, vector<int>(n));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cin >> mp[x][y];
        }
    }
    int l = -1, r = 1000000, m, bestDis;
    while (l < r - 1) {
        m = (l + r) / 2;
        bool f = 0;
        int minDis = 0;
        queue<PII> bfs;
        queue<int> dis;
        vector<vector<bool>> visited(n, vector<bool>(n));
        bfs.push(MP(0, 0));
        dis.push(0);
        visited[0][0] = 1;
        while (!bfs.empty()) {
            int x = bfs.front().first, y = bfs.front().second, d = dis.front();
            if (x == n - 1 && y == n - 1) {
                f = 1;
                minDis = d;
                break;
            }
            if (x > 0 && !visited[x - 1][y] && abs(mp[x][y] - mp[x - 1][y]) <= m) {
                bfs.push(MP(x - 1, y));
                dis.push(d + 1);
                visited[x - 1][y] = 1;
            }
            if (y > 0 && !visited[x][y - 1] && abs(mp[x][y] - mp[x][y - 1]) <= m) {
                bfs.push(MP(x, y - 1));
                dis.push(d + 1);
                visited[x][y - 1] = 1;
            }
            if (x < n - 1 && !visited[x + 1][y] && abs(mp[x][y] - mp[x + 1][y]) <= m) {
                bfs.push(MP(x + 1, y));
                dis.push(d + 1);
                visited[x + 1][y] = 1;
            }
            if (y < n - 1 && !visited[x][y + 1] && abs(mp[x][y] - mp[x][y + 1]) <= m) {
                bfs.push(MP(x, y + 1));
                dis.push(d + 1);
                visited[x][y + 1] = 1;
            }
            bfs.pop();
            dis.pop();
        }
        if (f) {
            r = m;
            bestDis = minDis;
        } else {
            l = m;
        }
    }
    cout << r << "\n" << bestDis << "\n";
    return 0;
}