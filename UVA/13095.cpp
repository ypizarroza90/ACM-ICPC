#include <bits/stdc++.h>
using namespace std;

int Matriz[100009][11];
int n, x, q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin>>n) {
		for (int i = 1; i <= n; i++) {
			cin>>x>>q;
			for (int j = 0; j < 10; j++)
				Matriz[i][j] = Matriz[i-1][j];
			Matriz[i][x]++;
		}
		for (int i = 0; i < q; i++) {
			int l, r, res = 0;
			cin>>l>>r;
			for (int j = 0; j < 10; j++)
				res += Matriz[r][j] - Matriz[l-1][j] > 0;
			cout<<res<<"\n";
		}
	}
	return 0;
}
