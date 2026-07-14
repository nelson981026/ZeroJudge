#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int e = 0, w = 0;
    cin >> s;
    for (char c : s) {
        if (c == 'E')
            e++;
        else
            w++;
    }
    if (w > e)
        cout << "West\n";
    else
        cout << "East\n";
    return 0;
}