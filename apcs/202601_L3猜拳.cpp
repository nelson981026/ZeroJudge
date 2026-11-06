#include <bits/stdc++.h>
using namespace std;
const int arr[3][3]={
    {0,-1,1},
    {1,0,-1},
    {-2,2,-2}
};
int main(){
    int n,a=0,b=0,x,y;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        a+=arr[x%4][y%4];
        b+=arr[y%4][x%4];
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}