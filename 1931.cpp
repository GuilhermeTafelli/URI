#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define INF 0x3f3f3f3f

typedef pair<long long int, long long int> ii;
typedef pair<long long int, ii> ip;

int a, b, dist[10010][3];
vector <vector <ii> > grafo;
int djk(){
    
    priority_queue<ip, vector<ip>, greater <ip> > q;
    memset(dist, INF, sizeof dist);
    q.push(ip(0, ii(1, 0)));
    dist[1][0] = 0;

    while(!q.empty()){
        ip topo = q.top();
        int distancia = topo.f;
        int vertice = topo.s.f;
        int p = topo.s.s;
       // cout << vertice << " " << distancia << " " << p << endl;
        q.pop();
        
        if(vertice == a and p%2 == 0)return dist[a][0];
        //cout << grafo[vertice].size() << endl;
        for(int i = 0;i<grafo[vertice].size();i++){
            int w = grafo[vertice][i].f;
            int custo = grafo[vertice][i].s;
            
            //cout << w << " " << custo << endl;
            if(dist[w][(p+1)%2] > distancia+custo){
                dist[w][(p+1)%2] = distancia+custo;
                q.push(ip(distancia+custo, ii(w, p+1)));
            }
        }
    }
    return -1;
}

int main(){
    int x, y, z;
    cin >> a >> b;
    
    grafo.resize(a+2);
    for(int i = 0;i<b;i++){
        scanf("%d %d %d", &x, &y, &z);

        grafo[x].push_back(ii(y, z));
        grafo[y].push_back(ii(x, z));
    }
    int r = djk();
    cout << r << endl;
}
