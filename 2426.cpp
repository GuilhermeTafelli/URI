#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
#define INF 0x3f3f3f3f
vector <vector<ii> > grafo;
int dist[510], vis[510][3], tmp = 0;
bool bfs(int x, int y){
	//cout << "!" << endl;
	queue <int> q;
	q.push(x);
	dist[x] = 0;
	while(!q.empty()){
		int w = q.front();
		q.pop();
		//cout << w <<"-------- " << tmp << endl;
		if(w == y)return true;
		for(int i = 0;i<grafo[w].size();i++){
			int r = grafo[w][i].first;
			int p = grafo[w][i].second;
			//cout << r << " " << p <<" " << dist[r] << endl;		
			if(vis[r][dist[w]%3] == 0 and p == 0 and dist[w]%3 != 0){
				q.push(r);
				vis[r][dist[w]%3] = 1;			
				dist[r] = dist[w]+1;
				//cout << "one" << endl;
			}
			if(vis[r][dist[w]%3] == 0 and p == 1 and dist[w]%3 == 0){
				q.push(r);
				vis[r][dist[w]%3] = 1;
				dist[r] = dist[w]+1;
				//cout << "two" << endl;
			}
		}
	}
	return false;
}

int main(){
	int a, b, c, d, x, y, z;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	grafo.resize(a+1);
	for(int i = 0;i<d;i++){
		scanf("%d%d%d", &x, &y, &z);
		grafo[x].push_back(make_pair(y, z));
	}
	memset(dist, 0, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	bool flag = bfs(b, c);
	if(!flag)cout << "*" << endl;
	else cout << dist[c] << endl;
}




