#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define LOGN 20
#define LOG(x)31-__builtin_clz(x)
#define i64 long long
#define endl '\n'
struct EDGE{
	int f, t, c;
	EDGE(){};
	EDGE(int from, int to, int cost):f(from),t(to),c(cost){};
	EDGE(int from, int cost): f(from), c(cost){};

	bool operator<(const EDGE E)const{
		return c < E.c;
	}
};

struct DSU{
	int* parent;
	int* rank;

	DSU(int N){
		parent = new int[N + 1];
		rank = new int[N + 1];

		for(int i=0;i<=N;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}

	int FIND(int x){
		return parent[x] == x ? x : parent[x] = FIND(parent[x]);
	}


	bool EQUALS(int x,int y){
		return FIND(x) == FIND(y);
	}


	void JOIN(int x,int y){
		int x1 = FIND(x), x2 = FIND(y);
		if(x1 == x2) return;
		if(rank[x1] == rank[x2]) ++rank[x1];
		if(rank[x1] < rank[x2])
			swap(x1,x2);

		parent[x2] = x1;
	}
};

int LCA[LOGN][MAXN], C[LOGN][MAXN], LEVEL[MAXN];
vector<vector<EDGE> > G;
vector<EDGE> EDGES;
bool VISIT[MAXN];

void INIT(int N){
	G.clear(), G.resize(N + 1);
	EDGES.clear();
	memset(VISIT, 0, sizeof(VISIT));
	memset(LEVEL, 0, sizeof(LEVEL));
	memset(LCA, -1, sizeof(LCA));
}


void DFS(int U){
	VISIT[U] = 1;
	for (int i = 0; i < G[U].size(); ++i){
		int v = G[U][i].f;
		if (!VISIT[v]){
			LCA[0][v] = U;
			C[0][v] = G[U][i].c;
			LEVEL[v] = LEVEL[U] + 1;
			int lg = LOG(LEVEL[v]);
			for (int j = 1; j <=lg; ++j){
				if (LCA[j-1][v] != -1){
					LCA[j][v] = LCA[j-1][LCA[j-1][v]];
					C[j][v] = max(C[j-1][v],C[j-1][LCA[j-1][v]]);
				}
			}
			DFS(v);
		}
	}
}

int ANCESTOR(int P, int Q){
	if (LEVEL[P] < LEVEL[Q])
		swap(P,Q);

	int lg = LOG(LEVEL[P]);
	if (LEVEL[P] != LEVEL[Q])
		for (int i = lg; i >= 0 ; --i)
			if(LEVEL[P]-(1<<i) >= LEVEL[Q])
				P = LCA[i][P];


	if (P == Q)
		return P;

	lg = LOG(LEVEL[P]);
	for (int i = lg; i >= 0; --i)
			if (LCA[i][P] != LCA[i][Q] && LCA[i][Q]!= -1)
				P = LCA[i][P], Q = LCA[i][Q];

	return LCA[0][P];
}

int QUERY(int P, int Q){
	int ans = -1;
	if (LEVEL[P] < LEVEL[Q])
		swap(P,Q);

	int lg = LOG(LEVEL[P]);
	if (LEVEL[P] != LEVEL[Q])
		for (int i = lg; i >= 0 ; --i)
			if(LEVEL[P]-(1<<i) >= LEVEL[Q]){
				ans = max(ans, C[i][P]);
				P = LCA[i][P];
			}
	return ans;
}

void MST(int N, int M){
	DSU S(N);
	sort(EDGES.begin(), EDGES.end());
	int T = 0;
	for (int i = 0; i < M && T < N-1; i++ ){
		int x = EDGES[i].f, y = EDGES[i].t;
		if(!S.EQUALS(x,y)){
			S.JOIN(x,y);
			G[x].push_back(EDGE(y, EDGES[i].c ));
			G[y].push_back(EDGE(x, EDGES[i].c ));
			T++;
		}
	}
}

int CAS,N,M,Q,X,Y,COST;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>CAS;
	for(int k = 1;k<=CAS; k++){
		cin>>N>>M;
		INIT(N);
		for (int i = 0; i < M; ++i)
		{
			cin>>X>>Y>>COST;
			EDGES.push_back(EDGE(X, Y, COST));
		}

		MST(N, M);
		DFS(1);

		cout<<"Case "<<k<<endl;
		cin>>Q;
		while(Q--){
			cin>>X>>Y;
			int lca = ANCESTOR(X, Y);
			cout<<max(QUERY(X, lca), QUERY(Y, lca))<<endl;
		}
		cout<<endl;
	}
	return 0;
}
