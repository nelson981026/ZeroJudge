#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,used=0,tar,l;
    cin>>n>>m;
    vector<int> point(n),task(m),pfs(n);
    for(auto &x:point){
            cin>>x;
    }
    for(auto &x:task){
            cin>>x;
    }
    pfs[0]=point[0];
    for(int i=1;i<n;++i){
            pfs[i]=point[i]+pfs[i-1];
    }
    for(auto x:task){
        tar=(x+used)%pfs[n-1];
        auto i=lower_bound(pfs.begin(),pfs.end(),tar);
        used=*i;
        l=i-pfs.begin();
    }
    printf("%d\n",(l+1)%n);
    return 0;
}
