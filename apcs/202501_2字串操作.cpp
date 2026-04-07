#include <bits/stdc++.h>
using namespace std;
string doubleExchange(string s){
	int n=s.length();
	for(int i=0;i<n/2;++i){
		swap(s[i*2],s[i*2+1]);
	}
	return s;
} 
string doubleSort(string s){
	int n=s.length();
	for(int i=0;i<n/2;++i){
		char a=min(s[i*2],s[i*2+1]),b=max(s[i*2],s[i*2+1]);
		s[i*2]=a;
		s[i*2+1]=b;
	}
	return s;
}
string perfectOrder(string s){
	int n=s.length();
	string tmp=s;
	for(int i=0;i<n/2;++i){
		tmp[i*2]=s[i];
		tmp[i*2+1]=s[i+n/2];
	}
	return tmp;
}
int main(){
	string s;
	int n,d;
	cin>>s>>n;
	for(int i=0;i<n;++i){
		cin>>d;
		switch(d){
			case 0:
				s=doubleExchange(s);
				break;
			case 1:
				s=doubleSort(s);
				break;
			case 2:
				s=perfectOrder(s);
				break;
		}
	}
	cout<<s;
	return 0;
}

