#include<bits/stdc++.h>
using namespace std;

int vis[1000], cont  = 0;
bool t[1000];
vector <vector<int> > grafo;

void dfs(int x, int y){
	vis[x] = 1;
	if(y !=-1){
		cont++;
		for(int i = 0;i<cont*2;i++){
			cout <<" "; 
		}
		cout << y << "-" << x << " pathR(G," << x << ")" << endl;
	}
	for(int i = 0;i<grafo[x].size();i++){
		int w = grafo[x][i];
		if(w != y and vis[w] == 0){
			dfs(w, x);
			cont--;
		}
		else {
			for(int i = 0;i<(cont+1)*2;i++){
				cout <<" "; 
			}	
			cout << x << "-" << w << endl;
		}
	}
}

int main(){
	int a, b, v, h, x, y;
	cin >> a;
	for(int i = 0 ;i<a;i++){
		cin >> v >> h;
		grafo.clear();
		grafo.resize(v+1);
		memset(vis, 0, sizeof(vis));
		memset(t, false, sizeof(t));
		for(int j = 0;j<h;j++){
			cin >> x >> y;
			grafo[x].push_back(y);
		}
		
		cout << "Caso " << i+1 << ":" << endl;
		
		for(int j = 0;j<v;j++){
			sort(grafo[j].begin(), grafo[j].end());
		}
		
		for(int j = 0;j<v;j++){
			cont = 0;
			sort(grafo[j].begin(), grafo[j].end());
			if(vis[j] == 0 and grafo[j].size() > 0){
				dfs(j, -1);		
				cout << endl;
			}
		}		
	}
}
