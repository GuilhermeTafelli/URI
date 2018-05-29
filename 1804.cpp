#include<bits/stdc++.h>
using namespace std;

vector <int> v, vet;
int a;

void update(int pos, int x){
	for(int i = pos;i<=a;i+=(i & -i)){
		v[i] +=x;
	}
}

int soma(int x){
	
	int cont =0;
	
	for(;x;x-=(x & -x)){
		cont+= v[x];
	}
	return cont;

}

int main(){
	int x, y;
	char s;
	
	cin >> a;
	v.assign(a+1, 0);
	
	for(int i = 1;i<=a;i++){
		cin >> x;
		vet.push_back(x);
		update(i, x);
	}
	getchar();
	while(cin >> s >> y){
		if(s == '?'){
			int r = soma(y-1);
			cout << r << endl;
		}
		else {
			update(y, -vet[y-1]);
		}
	}
}
