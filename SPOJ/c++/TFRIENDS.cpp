#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <stack>
#define MAXN 150
using namespace std;
vector<vector<int> >g;
int d[MAXN], low[MAXN], scc[MAXN],n,m,c,cont=1;
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;
 
void init(){
	memset(d,-1,sizeof(d));
	ticks=current_scc=0;
	while(!s.empty()){
		s.pop();
	}
}
void tarjan(int u){
	d[u] = low[u] = ticks++;
	s.push(u);
	stacked[u] = true;
	const vector<int> &out = g[u];
	for (int k=0, m=out.size(); k<m; ++k){
		const int &v = out[k];
		if (d[v] == -1){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if (stacked[v]){
			low[u] = min(low[u], low[v]);
		}
	}
	if (d[u] == low[u]){
		int v;
		do{
			v = s.top();
			s.pop();
			stacked[v] = false;
			scc[v] = current_scc;
		}while (u != v);
		current_scc++;
	}
}
int cas;
string cad;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		init();
		g.clear();
		g.resize(n+10);
		for(int i=0;i<n;i++){
			cin>>cad;
			for(int j=0;j<n;j++){
				if(cad[j]=='Y')
					g[i].push_back(j);
			}
		}
		for(int i=0;i<=n;i++){
			if(d[i]==-1){
				tarjan(i);
			}
		}
		cout<<current_scc-1<<'\n';
	}
	return 0;
}