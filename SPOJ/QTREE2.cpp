#include<bits/stdc++.h>
using namespace std;
#define MAXN 10009
#define LOG(x)31-__builtin_clz(x)
typedef long long i64;
struct edge{
	int from,cost;
	edge(int f=0,int c=0):from(f),cost(c){};
};
int LCA[17][MAXN],D[17][MAXN],level[MAXN];
vector<vector<edge> >G;
bool visit[MAXN];
void dfs(int u){
	visit[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i].from;
		if(!visit[v]){
			LCA[0][v]=u;
			level[v]=level[u]+1;
			D[0][v]=G[u][i].cost;
			int lg=LOG(level[v]);
			for(int j=1;j<=lg;j++){
				if(LCA[j-1][v]!=-1){
					LCA[j][v]=LCA[j-1][LCA[j-1][v]];
					D[j][v]=D[j-1][v]+D[j-1][LCA[j-1][v]];
				}
			}
			dfs(v);
		}
	}
}
int lca(int p,int q){
	if(level[p]<level[q])
		swap(p,q);
	int lg=LOG(level[p]);

	if(level[p]!=level[q])
		for(int i=lg;i>=0;i--)
			if(level[p]-(1<<i)>=level[q])
				p=LCA[i][p];
	if(p==q)
		return p;

	lg=LOG(level[p]);
	for(int i=lg;i>=0;i--){
		if(LCA[i][p]!=LCA[i][q]&&LCA[i][q]!=-1){
			p=LCA[i][p];
			q=LCA[i][q];
		}
	}

	return LCA[0][p];
}
int lca_distance(int p,int q,bool nodes=false){
	int ans=0;
	if(level[p]<level[q])
		swap(p,q);
	int lg=LOG(level[p]);
	for(int i=lg;i>=0;i--){
		if(level[p]-(1<<i)>=level[q]){
			ans+=(nodes)?(1<<i):D[i][p];
			p=LCA[i][p];
		}
	}
	return ans;
}
int K_th(int p,int q,int k){
	int antecesor=lca(p,q);
	int lca1=lca_distance(p,antecesor,true);
	int lca2=lca_distance(q,antecesor,true);
	if(k==1)
		return p;
	if(lca1+lca2+1==k)
		return q;
	if(k>lca1+1){
		swap(p,q);
		k=lca1+lca2+1-k;
	}else k--;
	int lvl=level[p]-k;
	int lg=LOG(level[p]);
	for(int i=lg;i>=0;i--)
		if(level[p]-(1<<i)>=lvl)
			p=LCA[i][p];
	return p;
}
void init(int n){
	G.clear();
	G.resize(n+10);
	memset(visit,0,sizeof(visit));
	memset(level,0,sizeof(level));
	memset(LCA,-1,sizeof(LCA));
}
int cas,n,x,y,c;
char cad[6];
int main()
{
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		init(n);
		for(int i=0;i<n-1;i++){
			scanf("%d%d%d",&x,&y,&c);
			G[x].push_back(edge(y,c));
			G[y].push_back(edge(x,c));
		}
		dfs(1);
		for(;;){
			scanf("%s",cad);
			if(cad[1]=='O')break;
			if(cad[1]=='I'){
				scanf("%d%d",&x,&y);
				int ant=lca(x,y);
				printf("%d\n",lca_distance(x,ant)+lca_distance(y,ant));
			}else{
				scanf("%d%d%d",&x,&y,&c);
				printf("%d\n",K_th(x,y,c));
			}
		}
		puts("");
	}

	return 0;
}
