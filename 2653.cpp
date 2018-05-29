#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int cont = 0;
    map<string, int > m;
    while(getline(cin, a)){
        if(m.count(a) == 0){
            m[a] = 1;
            cont++;
        }
    }
    cout << cont << endl;
}
