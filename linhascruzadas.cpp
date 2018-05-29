#include<bits/stdc++.h>
using namespace std;

vector <long long int> v;
long long int a;

void update(long long int pos, long long int x){
	for(long long int i = pos;i<=a;i+= (i & -i)){
		v[i] += x;
	}
}

long long int soma(long long int x){
	long long int cont = 0;
	for(;x; x -= (x & -x)){
		cont+=v[x];
	}
	return cont;
}

int main(){
	long long int x, r = 0;
	cin >> a;
	
	v.assign(a+1, 0);
	
	for(long long int i = 1;i<=a;i++){
		cin >> x;
		update(x, 1);
		long long int d = soma(x);
		r += x-d;
	}
	cout << r << endl;
}
