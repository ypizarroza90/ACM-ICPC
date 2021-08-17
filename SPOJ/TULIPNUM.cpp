#include <bits/stdc++.h>
using namespace std;

int cumulative[100009];
int n, x, y, q,cas;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	for (int k = 1; k <= cas; ++k)
	{
		cout<<"Case "<<k<<":\n";
		cin>>n>>q;
		cin>>y;
		cumulative[0] = 0, cumulative[1] = 1;
		for (int i = 1; i < n; i++) {
			cin>>x;
			if (x != y)
				cumulative[i+1] = cumulative[i] + 1;
			else
				cumulative[i+1]=cumulative[i];
			y = x;
		}
		for (int i = 0; i < q; i++) {
			int l, r, res = 0;
			cin>>l>>r;
			if(cumulative[l] != cumulative[l-1])
				cout<<cumulative[r]-cumulative[l-1]<<'\n';
			else
				cout<<cumulative[r]-cumulative[l-1]+1<<'\n';		
		}
	}
	return 0;
}
