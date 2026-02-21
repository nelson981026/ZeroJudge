#include <bits/stdc++.h>
using namespace std;
bool isInt(char c) {
    return c >= '0' && c <= '9';
}
long long toInt(string str) {
    long long ret = 0;
    for (char c : str) {
        ret *= 10L;
        ret += c - '0';
    }
    return ret;
}
long long detla(vector<long long> v) {
    long long min = v[0], max = v[0];
    for (long long x : v) {
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }
    return max - min;
}
long long getValue(string str) {
    int lth = str.length();
    int i, level = 0, last = 1;
    if (str[0] == 'f' && str[lth - 1] == ')') {
        vector<long long> tmp;
        for (i = 1; i < lth - 1; ++i) {
            if (str[i] == '(')
                level++;
            if (str[i] == ')')
                level--;
            if (level == 1 && str[i] == ',') {
                tmp.emplace_back(getValue(str.substr(last + 1, i - last - 1)));
                last = i;
            }
            if (level == 0)
                goto f;
        }
        tmp.emplace_back(getValue(str.substr(last + 1, i - last - 1)));
        // cout<<str<<"(1)="<<detla(tmp)<<endl;
        return detla(tmp);
    }
f:
    for (i = 0, level = 0; i < lth; ++i) {
        if (str[i] == '(')
            level++;
        if (str[i] == ')')
            level--;
        if (str[i] == '*' && level == 0)
            return getValue(str.substr(0, i)) * getValue(str.substr(i + 1));
    }
    for (i = 0, level = 0; i < lth; ++i) {
        if (str[i] == '(')
            level++;
        if (str[i] == ')')
            level--;
        if (str[i] == '+' && level == 0)
            return getValue(str.substr(0, i)) + getValue(str.substr(i + 1));
    }
    return toInt(str);
}
int main() {
    string str;
    cin >> str;
    cout << getValue(str);
    return 0;
}