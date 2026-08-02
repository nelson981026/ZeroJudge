#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> child;
vector<int> depth;
int howDeep(int i){
    if(depth[i]>=0){
        return depth[i];
    } else{
        int maxa=0;
        for(int c:child[i]){
            maxa=max(maxa,howDeep(c)+1);
        }
        return maxa;
    }
    return 0;
}
int main(){
    int n,a,b,maxa=0;
    cin>>n;
    child.resize(n);
    depth.resize(n);
    fill(depth.begin(),depth.end(),-1);
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        child[a].emplace_back(b);
    }
    for(int i=0;i<n;++i){
        depth[i]=howDeep(i);
    }
    for(int i=0;i<n;++i){
        int m1=-1,m2=-1;
        for(int c:child[i]){
            if(depth[c]>m1){
                m2=m1;
                m1=depth[c];
            } else if(depth[c]>m2){
                m2=depth[c];
            }
        }
        maxa=max(maxa,m1+m2+2);
    }
    cout<<maxa;
    return 0;
}