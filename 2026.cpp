#include<bits/stdc++.h>
using namespace std;

int a, b, c, d, x, y, dp[1010][1010];

vector<int> p, q;   

int m(int i, int rest){

    if(i == c or !rest)return dp[i][rest] = 0;
    if(dp[i][rest] != -1)return dp[i][rest];
    
    int x = m(i+1, rest);
    
    if(rest >= p[i]){
    
        int y = q[i]+m(i+1, rest-p[i]);
        return dp[i][rest] = max(x, y);
    }
    return dp[i][rest] = x;
}


int main(){
    
    cin >> a;
    
    for(int i= 0;i<a;i++){
        cin >> c >> d;
        
        memset(dp, -1, sizeof dp);
        p.clear();
        q.clear();
        
        for(int j =0;j<c;j++){
            cin >> x >> y;
            q.push_back(x);
            p.push_back(y); 
        }
        int r = m(0, d);
        cout << "Galho "<< i+1 << ":" << endl;
        cout << "Numero total de enfeites: " << r << endl;
        cout << endl;
    }
}
