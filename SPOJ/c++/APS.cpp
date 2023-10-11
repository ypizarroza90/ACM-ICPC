#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAX 10000001
vector<int> pl, phi, mp;
vector<i64>acum;
void fast_sieve(int n) {
	pl.clear();
	phi.assign(n, 1);
	mp.assign(n, 0);
	for (int i = 2; i < n; ++i) {
		if (!mp[i]) {
			pl.push_back(i);
			mp[i] = i;
			phi[i] = i - 1;
		}
		for (size_t j = 0; j < pl.size() && i * pl[j] < n; ++j) {
			int p = pl[j];
			mp[i * p] = p;
			phi[i * p] = phi[i] * (p - !!(i % p));
			if (i % p == 0)
				break;
		}
	}
}

int cas,n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fast_sieve(MAX);
	acum.assign(MAX, 0);
	for(int i=2;i<MAX;i++){
		acum[i] = (i64)mp[i] + acum[i-1];
	}
	cin>>cas;
	for(int i=1;i<=cas;i++){
		cin>>n;
		cout<<acum[n]<<'\n';
	}
}
