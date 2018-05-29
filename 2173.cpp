#include <bits/stdc++.h>
using namespace std;

typedef pair <int, pair <int, int> > ip;
typedef pair <int, int> ii;

vector <int> v;
vector <ip> q;

int a, b;

int pai(int x){
	return (v[x] == x) ? x : (v[x] = pai(v[x]));
}
bool juntar(int i, int j){
	int x = pai(i);
	int y = pai(j);
	
	if(x == y)return false;
	
	v[max(x, y)] = min(x, y);
	return true;
}
int kruskal(bool flag){

	int cont = 0;	

	for(int i = 1;i<=a;i++){
		v[i] = i;
	}
	if(flag == true){
	
		for(int i = 0;i < q.size();i++){ 
			int x = q[i].second.first;
			int y = q[i].second.second;
			int custo = q[i].first;
			
			if(juntar(x, y))cont+=custo;
		}
	}
	else {
		for(int i = q.size()-1;i>=0;i--){ 
			int x = q[i].second.first;
			int y = q[i].second.second;
			int custo = q[i].first;

			if(juntar(x, y))cont+=custo;
		}
	}	
	return cont;
}
int main(){
	while(cin >> a >> b, a|b){
		
		int r1 = 0, r2 = 0, x, y, z;
		
		v.clear();
		q.clear();
		v.resize(a+2);
		q.resize(b+2);
		
		for(int i = 0;i<b;i++){
			cin >> x >> y >> z;
			q.push_back(make_pair(z, ii(x, y)));	
		}
		sort(q.begin(), q.end());
		//cout << "!" << endl;
		r1 = kruskal(true);
		r2 = kruskal(false);
		cout << r2-r1 << endl;
	}
}
