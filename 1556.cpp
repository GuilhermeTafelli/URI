#include<bits/stdc++.h>
using namespace std;

vector < string > r;
map <string, int> m;
string v, s;
int t = 0;

void rec(int cont, int i){
	if(cont >= t)return;
	
	s+=v[i];
	if(m.count(s) == 0){
		r.push_back(s);
		m[s] = 1;
	}
	rec(cont+1, i+1);
	s.pop_back();
	rec(cont+1, i+1);
}

int main(){
	while(getline(cin, v)){
		
		s.clear();
		r.clear();
		m.clear();
		
		t = v.size();
		rec(0, 0);
		sort(r.begin(), r.end());
		for(int i = 0;i < r.size();i++){
			cout << r[i] << endl;
		}
	}
}
