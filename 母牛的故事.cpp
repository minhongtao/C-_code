#include <bits/stdc++.h>
using namespace std;
int cow[56]={0,1,2,3,4};
int f(int n){
	if(cow[n]==0){
		cow[n]=f(n-1)+f(n-3);
		return cow[n];
	} else{
		return cow[n];
	}
}
int main()
{
	int n;
	while(cin>>n&&n) cout<<f(n)<<endl;
	return 0;
}
