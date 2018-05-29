#include <bits/stdc++.h>
using namespace std;

#define INF 100010
vector <int> v;

void update(int pos, int x){
	for(int i = pos;i<INF;i += (i & -i)){
		v[i] += x;
	}
}

int soma(int x){
	int cont = 0;
	for(;x; x-=(x & -x)){
		cont += v[x];
	}
	return cont;
}

int main(){
	int a, b, x, y, cont, d;
	while(scanf("%d%d", &a, &b) != EOF){
		cont = 0;
		v.assign(INF, 0);
		for (int i = 1; i <= b; i++){
			scanf("%d%d", &x, &y);
			if(x-a-1 < 0)d = 0;
			else d = x-a-1;
			if(soma(x+a)-soma(d) <= y){
				update(x, 1);
				cont++;
			}
		}
		cout << cont << endl;
	}
}
