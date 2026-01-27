#include <bits/stdc++.h>
using namespace std;
int min(int a,int b){
	return (a>b)?(b):(a);
}
int main() {
	int n,ret=0;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	if(a[0]==0)		ret+=a[1];
	if(a[n-1]==0)	ret+=a[n-2];
	for(int i=1;i<n-1;++i){
		if(a[i]==0){
			ret+=min(a[i-1],a[i+1]);
		}
	}
	cout<<ret<<endl;
	return 0;
}
