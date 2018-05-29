#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long int x;
	while(scanf("%llu", &x), x != -1){
		if(x == 0)cout << 0 << endl;
		else cout << x-1 << endl;
	}
}
