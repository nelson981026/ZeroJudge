#include<bits/stdc++.h>
using namespace std;
int main(){
	int tmp,max=0;
	vector<int> cou(10);
	for(int i=0;i<3;++i){
		cin>>tmp;
		cou[tmp]++;
	}
	for(int i=0;i<10;++i){
		if(cou[i]>max){
			max=cou[i];
		}
	}
	cout<<max;
	for(int i=9;i>=0;--i){
		if(cou[i]){
			cout<<" "<<i;
		}
	}
	return 0;
}
