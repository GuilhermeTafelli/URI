#include<bits/stdc++.h>
using namespace std;

int main(){
    bitset<51> s;
    long long int a, x, m = 0, cont = 0;
    bool flag = false;
    string c;
    cin >> a;
    for(int i = 0;i<a;i++){
        flag = false, m = 0, cont = 0;
        cin >> x;
        s = x;
        c = s.to_string();

        for(int j = 0;j<c.size();j++){
            if(flag == false and c[j] == '1'){
                flag = true;
                cont = 0;
            }
            if(flag == true and c[j] ==  '1')cont++;
            if(flag == true and (c[j] == '0' or j == c.size()-1)){
                m = max(m, cont);
                flag = false;
            }
        }
        m = max(m, cont);
        cout << m << endl;
    }
    
}
