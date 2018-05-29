#include<bits/stdc++.h>
using namespace std;

int a, b, t, dp[100000][1000];
vector <int> m;

int source(int i, int rest){
   
    if(rest == b)return dp[i][rest] = 1;
    if(i == a or rest > b)return 0;
    if(dp[rest][i] != -1)return dp[i][rest];
    
    
    int x = source(i+1, rest);                    
    
    if(rest+m[i]<=b){
        int y = source(i+1, rest+m[i]);
        return dp[i][rest] = max(x, y);
    }
    return dp[i][rest] = x;                
}

int main(){
    cin >> b >> a;
    memset(dp, -1, sizeof dp);
    for(int i = 0;i<a;i++){
        cin >> t;
        m.push_back(t);
    }
    int r = source(0, 0);
    if(r == 0)cout << "N" << endl;
    else cout << "S" << endl;
    
}
