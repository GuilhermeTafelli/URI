#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, x, y, z, r = 0, cont;
    cin >> a;
    for(int i = 0;i<a;i++){
        cont = 0, r = 0;
        cin >> x >> y;
        for(int j = 0;j<x;j++){
            cin >> z;
            if(cont+z > y){
                r++;
                cont = z;
            }
            else cont+=z;
        }
        cout << r+1 << endl;
    }
    

}
