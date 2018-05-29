#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int dist[10000];
vector <vector <int> > grafo;


int bfs(int x, int y){
	queue <int> q;
	memset(dist, INF, sizeof(dist));
	dist[x] = 0;
	q.push(x);
	while(!q.empty()){
		int w = q.front();
		q.pop();
		for(int i = 0;i<grafo[w].size();i++){
			int p = grafo[w][i];
			if(dist[p] > dist[w]+1){
				dist[p] = dist[w]+1;
				q.push(p);
			}
			if(p == y)return dist[p];
			
		}
	}
}

int main(){
	map <string, int> m;
	int a, b, queijo, e, s, cont = 0;
	string x, y;
	cin >> a >> b;
	grafo.resize(a);
	for(int i = 0; i<b; i++){
		cin >> x >> y;
		if(m.count(x) == 0){
			m[x] = cont;
			cont++;
		}
		if(m.count(y) == 0){
			m[y] = cont;
			cont++;
		}
		grafo[m[x]].push_back(m[y]);	
		grafo[m[y]].push_back(m[x]);
	} 

	int r = 0;
	r+= bfs(m["Entrada"], m["*"]);
	r+= bfs(m["*"], m["Saida"]);
	cout << r << endl;
}
