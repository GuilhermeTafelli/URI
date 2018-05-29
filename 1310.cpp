#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    
    while(cin >> a){
    
        int x, soma = 0, ans = 0, b;    
        
        cin >> b;
        for(int i =0;i<a;i++){
            cin >> x;
            x-=b;
            soma +=x;
            
            ans = max(ans, soma);
            if(soma < 0)soma = 0;
        }
        cout << ans << endl;
    
    }

}
