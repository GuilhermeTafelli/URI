#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	while(scanf("%d", &x), x!=0){
		bool flag = true;
		int i = 1;
		while(i*i <=x){
			if(flag){
				printf("%d", i*i);
				flag = false;
			}
			else printf(" %d", i*i);
			i++;
		}
		printf("\n");
	}
}
