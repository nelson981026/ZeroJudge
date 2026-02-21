#include <bits/stdc++.h>
using namespace std;
int m, n, id;
vector<string> mp;
vector<vector<int>> group;
vector<int> cnt;
static unordered_set<char> l{'H', '7', 'X', 'J'};
static unordered_set<char> r{'F', 'H', 'X', 'L'};
static unordered_set<char> u{'X', 'I', 'L', 'J'};
static unordered_set<char> d{'F', '7', 'I', 'X'};

void search(pair<int, int> p) {
    if (group[p.first][p.second] > 0)
        return;
    group[p.first][p.second] = id;
    char tmp = mp[p.first][p.second];
    mp[p.first][p.second] = '0';
    if (p.second - 1 >= 0 && l.count(tmp) && r.count(mp[p.first][p.second - 1]))
        search({p.first, p.second - 1});
    if (p.second + 1 < n && r.count(tmp) && l.count(mp[p.first][p.second + 1]))
        search({p.first, p.second + 1});
    if (p.first - 1 >= 0 && u.count(tmp) && d.count(mp[p.first - 1][p.second]))
        search({p.first - 1, p.second});
    if (p.first + 1 < m && d.count(tmp) && u.count(mp[p.first + 1][p.second]))
        search({p.first + 1, p.second});
}

int main() {
    int maxa = 0;
    id = 0;
    cnt.emplace_back(0);
    cin >> m >> n;
    mp.resize(m);
    group.resize(m);
    for (int x = 0; x < m; ++x) {
        cin >> mp[x];
        group[x].resize(n);
    }
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (mp[x][y] != '0') {
                ++id;
                cnt.emplace_back(0);
                search({x, y});
            }
        }
    }
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            cnt[group[x][y]]++;
        }
    }
    for (int i = 1; i < cnt.size(); ++i)
        if (cnt[i] > maxa)
            maxa = cnt[i];
    cout << maxa;
    return 0;
}