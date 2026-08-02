#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
void mpInsert(string s){
    if(mp.count(s)){
        mp[s]++;
    } else {
        mp.insert(make_pair(s,1));
    }
}
void mpErase(string s){
    if(mp[s]>1){
        mp[s]--;
    } else {
        mp.erase(s);
    }
}
int main(){
    int n,m,cnt=0;
    cin>>m>>n;
    vector<string> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    for(int i=0;i<m;++i){
        mpInsert(v[i]);
    }
    for(int i=0;i<n-m;++i){
        cnt+=(mp.size()==m);
        mpErase(v[i]);
        mpInsert(v[i+m]);
    }
    cnt+=(mp.size()==m);
    cout<<cnt<<endl;
    return 0;
}