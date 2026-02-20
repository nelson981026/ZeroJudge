#include <bits/stdc++.h>
using namespace std;
unordered_set<string> us;
pair<string, int> k, s;
int l;
string sch(string str) {
    if (str.length() == l) {
        if (us.count(str)) {
            return "";
        } else {
            return str;
        }
    }
    for (int i = 0; i < k.second; ++i) {
        string tmp = sch(str + k.first[i]);
        if (tmp != "") {
            return tmp;
        }
    }
    return "";
}
int main() {
    cin >> k.first;
    k.second = k.first.length();
    cin >> l;
    cin >> s.first;
    s.second = s.first.length();
    for (int i = 0; i <= s.second - l; ++i) {
        us.insert(s.first.substr(i, l));
    }
    cout << sch("") << endl;
    return 0;
}