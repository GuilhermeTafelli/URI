#include<bits/stdc++.h>
using namespace std;

int a, b, x, y, dp[1010][1010];
vector <int> r, p;
int m(int i, int rest){


    if(i == b or !rest)return dp[i][rest] = 0;
    if(dp[i][rest] != -1)return dp[i][rest];
    
    int x = m(i+1, rest);
    
    if(rest >= p[i]){
        int y = r[i]+m(i+1, rest-p[i]);
        return dp[i][rest] = max(x, y);
    }
    
    return dp[i][rest] = x;
    
}

int main(){
    cin >> a;
    while(a--){
        cin >> b;
        
        memset(dp, -1, sizeof dp);
        r.clear();
        p.clear();
        
        for(int i = 0;i<b;i++){
            cin >> x >> y;
            r.push_back(x);
            p.push_back(y);
        }
        cin >> x >> y;

        int r = m(0, x);
        if(r >=y)cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl;
    }

}
