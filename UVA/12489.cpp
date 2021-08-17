#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi children, subtreeLabels, tree, L;
vi pred, mapa;
int cas,n,x,y;

bool compare(int a, int b) {
	return subtreeLabels[a] < subtreeLabels[b];
}

bool equals(int a, int b) {
	return subtreeLabels[a] == subtreeLabels[b];
}

void generateMapping(int r1, int r2) {
	mapa.resize(n);
	mapa[r1] = r2 - n;
	sort(children[r1].begin(), children[r1].end(), compare);
	sort(children[r2].begin(), children[r2].end(), compare);
	for (int i = 0; i < (int) children[r1].size(); i++) {
		int u = children[r1][i];
		int v = children[r2][i];
		generateMapping(u, v);
	}
}

vi findCenter(int offset = 0) {
	int cnt = n;
	vi a;
	vi deg(n);
	for (int i = 0; i < n; i++) {
		deg[i] = tree[i + offset].size();
		if (deg[i] <= 1) {
			a.push_back(i + offset);
			--cnt;
		}
	}
	while (cnt > 0) {
		vi na;
		for (int i = 0; i < (int) a.size(); i++) {
			int u = a[i];
			for (int j = 0; j < (int) tree[u].size(); j++) {
				int v = tree[u][j];
				if (--deg[v - offset] == 1) {
					na.push_back(v);
					--cnt;
				}
			}
		}
		a = na;
	}
	return a;
}

int dfs(int u, int p = -1, int depth = 0) {
	L[depth].push_back(u);
	int h = 0;
	for (int i = 0; i < (int) tree[u].size(); i++) {
		int v = tree[u][i];
		if (v == p)
			continue;
		pred[v] = u;
		children[u].push_back(v);
		h = max(h, dfs(v, u, depth + 1));
	}
	return h + 1;
}

bool rootedTreeIsomorphism(int r1, int r2) {
	L.assign(n, vi());
	pred.assign(2 * n, -1);
	children.assign(2 * n, vi());

	int h1 = dfs(r1);
	int h2 = dfs(r2);
	if (h1 != h2)
		return false;

	int h = h1 - 1;
	vi label(2 * n);
	subtreeLabels.assign(2 * n, vi());

	for (int i = h - 1; i >= 0; i--) {
		for (int j = 0; j < (int) L[i + 1].size(); j++) {
			int v = L[i + 1][j];
			subtreeLabels[pred[v]].push_back(label[v]);
		}

		sort(L[i].begin(), L[i].end(), compare);

		for (int j = 0, cnt = 0; j < (int) L[i].size(); j++) {
			if (j && !equals(L[i][j], L[i][j - 1]))
				++cnt;
			label[L[i][j]] = cnt;
		}
	}

	if (!equals(r1, r2))
		return false;

	generateMapping(r1, r2);
	return true;
}

bool treeIsomorphism() {
	vi c1 = findCenter();
	vi c2 = findCenter(n);
	if (c1.size() == c2.size()) {
		if (rootedTreeIsomorphism(c1[0], c2[0]))
			return true;
		else if (c1.size() > 1)
			return rootedTreeIsomorphism(c1[1], c2[0]);
	}
	return false;
}
int main() {
	while(scanf("%d",&n)==1){
		vvi t1(n);
		for(int i=0;i<n-1;i++){
			scanf("%d%d",&x,&y);
			x--,y--;
			t1[x].push_back(y);
			t1[y].push_back(x);
		}
		vvi t2(n);
		for(int i=0;i<n-1;i++){
			scanf("%d%d",&x,&y);
			x--,y--;
			t2[x].push_back(y);
			t2[y].push_back(x);
		}
		tree.assign(2 * n, vi());
		for (int u = 0; u < n; u++) {
			for (int i = 0; i < t1[u].size(); i++) {
				int v = t1[u][i];
				tree[u].push_back(v);
			}
			for (int i = 0; i < t2[u].size(); i++) {
				int v = t2[u][i];
				tree[u + n].push_back(v + n);
			}
		}

		bool res = treeIsomorphism();
		printf("%s\n",res?"S":"N");
	}
}
