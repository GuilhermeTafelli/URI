
#include <bits/stdc++.h> 
using namespace std;

#define f first
#define s second
#define INF 10000000000000LL

typedef pair<int, int > ii;
typedef pair<long long int, ii> ip;

long long int grafo[110][110], dist[110][110], a, b;
ii m[] = {ii(1, 0), ii(-1, 0), ii(0, 1), ii(0, -1)};

long long int cp(int long long n){
    long long int p[] = {n , 1, n+1, 0};
    return p[n%4];
}

long long int c(long long int x, long long int y){
    long long int k = min(x, y), j = max(x, y);
    return cp(k-1)^cp(j);
}
    
long long int djk(){
    priority_queue<ip, vector<ip>, greater<ip> >q;
    
    
    q.push(make_pair(0, ii(1, 1)));
    
    dist[1][1] = 0;
    
    while(!q.empty()){
        ip topo = q.top();
        int x = topo.s.f;
        int y = topo.s.s;
        long long int distancia = topo.f;
        //cout << x << " " << y << " " << distancia<< endl;        
        q.pop();
        if(a == x and b == y)return dist[a][b];
        if(distancia > dist[x][y])continue;
        for(int i = 0;i<4;i++){
            //cout << m[i].f << " " << m[i].s << endl;
            if(x+m[i].f >= 1 and x+m[i].f<=a and y+m[i].s >= 1 and y+m[i].s<=b){
                
                long long int custo = c(grafo[x][y], grafo[x+m[i].f][y+m[i].s]);
             
          //cout << custo << endl;
                if(dist[x+m[i].f][y+m[i].s] > custo+distancia){
                    dist[x+m[i].f][y+m[i].s] = custo+distancia;
                    q.push(make_pair(dist[x+m[i].f][y+m[i].s], ii(x+m[i].f, y+m[i].s)));
                }
            }
        }
    
    }
    return dist[a][b];
}


int main(){
    int x;
    while(scanf("%lld %lld", &a, &b)){
        for(long long int i = 1;i<=a;i++){
            for(long long int j = 1;j<=b;j++){
                scanf("%lld", &grafo[i][j]);
                dist[i][j] = INF;
            }
        }
        long long int r = djk();
        printf("%lld\n", r);
    }
} 



