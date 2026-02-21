#include <bits/stdc++.h>
using namespace std;
int main() {
    long long cnt = 0;
    unordered_set<string> s;
    int m;
    cin >> m;
    string str;
    for (int i = 0; i < m; ++i) {
        cin >> str;
        s.insert(str);
    }
    for (string str : s) {
        int l = str.length();
        for (int i = 1; i * 2 < l; ++i) {
            if (str.substr(0, i) == str.substr(l - i, i) && s.count(str.substr(i, l - 2 * i))) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}