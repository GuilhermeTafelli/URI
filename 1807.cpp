#include<bits/stdc++.h>
using namespace std;

long long int mod = (1LL << 31)-1LL;
long long int expofast(long long int x){
	
	if(x == 0)return 1;
	long long a = expofast(x/2);
	a = (a*a)%mod;
	
	if(x&1){
		a = (a*3)%mod; 
	}
	return a;
}


int main(){
	long long int a;
	cin >> a;
	cout << expofast(a) << endl;
}
