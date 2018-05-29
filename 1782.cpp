#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

long long int p[100010], q[100010];
vector <pair <int, ii> >grafo;

int forma(int a){
    for(int i = 1;i<=a;i++){
        p[i] = i;    
        q[i] = 1;
    }
}
int pai(int a){
    return (p[a] == a) ? a : (p[a] = pai(p[a]));
}

int junta(int a, int b){
    int x = pai(a);
    int y = pai(b);
    
    if(x == y)return -1;
    //cout << x << " --- " << y << endl;
    q[p[min(x, y)]] += q[p[max(x, y)]];
    p[max(x, y)] = min(x, y);
  
}

int main(){
    
    int n, x, y, z, b, ans, a;
    cin >> n;
    for(int j = 0;j<n;j++){
        
        
        scanf("%d", &a);
        
        forma(a); 
        set <long long int> l;
        long long int v[1000010], last = 0;
        memset(v, 0, sizeof v);
        grafo.clear();
        
        for(int i =0;i<a-1;i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo.push_back(make_pair(z, ii(x, y)));
            l.insert(z);
        }
        
        l.insert(0);
        sort(grafo.begin(), grafo.end());    
    
        for(int i = 0;i<a-1;i++){
            int custo = grafo[i].first;
           
            y = grafo[i].second.second;
            x = grafo[i].second.first;
    
            long long int cx = (q[p[x]]*(q[p[x]]-1))/2;
            long long int cy = (q[p[y]]*(q[p[y]]-1))/2;
            
                    
            junta(x, y);
           
            if(last != custo)v[custo] = v[last]; 
            
            v[custo]+=  ((q[p[x]]*(q[p[x]]-1))/2)-(cx+cy);
            //cout << v[custo] << endl;    
            last = custo;
        }
        
        scanf("%d", &b);
        cout << "Caso #" << j+1 << ":";
        for( int i = 0;i<b;i++){
            scanf("%d", &x);
            set<long long int> :: iterator it = l.upper_bound(x);
            it--;
           
            if(it != l.end())cout << " " << v[*it]+a;
        }
        cout << endl;
    }
}

