#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
 
int Q, op,x,y;
string cad;
rope<char> r[10001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cin>>cad;
	for(char c: cad)
		r[0].push_back(c);
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>op;
		r[i] = r[i-1];
		if (op == 1){
			cin>>x>>y;
			if(x > y)
				swap(x,y);
			rope<char> n = r[i].substr(x,y-x+1);
			r[i].erase(x,y-x+1);
			r[i].insert(r[i].mutable_begin(), n);
		}
		else if(op == 2){
			cin>>x>>y;
			if(x > y)
				swap(x,y);
			rope<char> s = r[i].substr(x,y-x+1);
			r[i].erase(x,y-x+1);
			r[i].insert(r[i].mutable_end(), s);
		}
		else if(op == 3){
			cin>>x;
			cout<<r[i-1][x]<<'\n';
		}
		else{
			cin>>x>>y;
			cout<<r[x][y]<<'\n';
		}
	}
}