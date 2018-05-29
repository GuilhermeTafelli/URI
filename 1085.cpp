#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <int, int> ii;
typedef pair <int, pair <int, char> > ic;

vector < vector <ic> > grafo;
int dist[1000];

int djk(int x, int y){
	priority_queue < ic, vector <ic>, greater <ic> > q;
	memset(dist, INF, sizeof(dist));
	int r = INF;
	
	dist[x] = 0;
	q.push(make_pair(0, make_pair(x, '.')));
	while(!q.empty()){
		ic topo = q.top();
		q.pop();
		int vertice = topo.second.first;
		int distancia = topo.first;
		char fl = topo.second.second;
		
		cout << vertice << " " << distancia << " " << fl << "-------" <<endl;
		if(vertice == y)return dist[vertice];
		
		for(int i = 0;i<grafo[vertice].size();i++){
			
			int destino = grafo[vertice][i].first;
			int custo = grafo[vertice][i].second.first;
			char pl = grafo[vertice][i].second.second;
			
			cout << destino << " " << custo << " " << pl << endl;
			if(dist[destino] > dist[vertice]+custo and fl != pl){
				dist[destino] = dist[vertice]+custo;
				q.push(make_pair(dist[destino], make_pair(destino, pl)));
				cout << "e1"<< endl;
			}
		}
	}
	return INF;
}


int main(){
	int a;
	while(cin >> a, a){
		int cont = 2;
		map <string, int> m;
		grafo.resize(a+2);
		grafo.clear();
		string ori, dest, x, y, z;
		cin >> ori >> dest;
		m[ori] = 0;
		m[dest] = 1;
		//cout << ori << " " << dest << endl;
		for(int i = 0;i<a;i++){
			cin >> x >> y >> z;
			if(m.count(x) == 0){
				m[x] = cont;
				cont++;
			}
			if(m.count(y) == 0){
				m[y] = cont;
				cont++;
			}
			int t = z.size();
			grafo[m[x]].push_back(make_pair(m[y], make_pair(t, z[0])));
			grafo[m[y]].push_back(make_pair(m[x], make_pair(t, z[0])));
		}
		//cout << "!" << endl;
		int r = djk(m[ori], m[dest]);
		if(r == INF)cout << "impossible" << endl;
		else cout << r << endl;
	}

}
