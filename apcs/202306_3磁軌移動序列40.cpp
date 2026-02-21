#include <bits/stdc++.h>
using namespace std;
long long sum;
int now;
int toInt(string str) {
    int ret = 0;
    for (auto c : str) {
        ret *= 10;
        ret += c - '0';
    }
    return ret;
}
void T(string str);
void L(string str, int time);
int main() {
    sum = 0, now = 10;
    string str;
    cin >> str;
    T(str.substr(3));
    cout << sum;
    return 0;
}
void T(string str) {
    if (str[0] == 'T') {
        sum += abs(now - toInt(str.substr(1, 2)));
        now = toInt(str.substr(1, 2));
        T(str.substr(3));
    } else if (str[0] == 'L') {
        L(str.substr(2), toInt(str.substr(1, 1)));
    }
}
void L(string str, int time) {
    int l = str.length(), cl = 0, ce = 0,i;
    for (i = 0; i < l; ++i) {
        if(str[i]=='L') cl++;
        if(str[i]=='E') ce++;
        if(ce>cl)   break;
    }
    for(int t=0;t<time;++t){
        T(str.substr(0,i));
    }
    T(str.substr(i+1));
}