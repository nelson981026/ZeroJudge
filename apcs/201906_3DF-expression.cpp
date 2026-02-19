#include <bits/stdc++.h>
using namespace std;
string s;
int n, i;
int cnt(int deep) {
    if (s[i] == '0') {
        i++;
        return 0;
    }
    if (s[i] == '1') {
        i++;
        return (n * n) >> (2 * deep);
    }
    i++;
    return cnt(deep + 1) + cnt(deep + 1) + cnt(deep + 1) + cnt(deep + 1);
}
int main() {
    cin >> s >> n;
    i = 0;
    cout << cnt(0);
    return 0;
}