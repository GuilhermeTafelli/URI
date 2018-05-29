#include<bits/stdc++.h>
using namespace std;

int a, b, c, dp[45][143][143], x, y;
vector <int> am, v;

int m(int i, int verde, int amarelo){
    if(i == a)return dp[i][verde][amarelo] = 0;
    if(dp[i][verde][amarelo] != -1) return dp[i][verde][amarelo];
    int k = m(i+1, verde, amarelo);
    int j;
    if(verde+v[i] >=0 and amarelo+am[i] >= 0)
        j = 1+m(i+1, verde+v[i], amarelo+am[i]); 
    return dp[i][verde][amarelo] = max(k, j);
}


int main(){
    
    while(scanf("%d", &a) != EOF){
        am.clear();
        v.clear();
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &b, &c);
        for(int i = 0;i<a;i++){
            scanf("%d %d", &x, &y);
            v.push_back(x);
            am.push_back(y);
        }
        
        int r = m(0, b, c);
        cout << r << endl;
    }
    

}
