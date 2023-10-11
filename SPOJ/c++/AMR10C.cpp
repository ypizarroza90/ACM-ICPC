#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAX 10001
vector<int> pl, phi, mp;
vector<i64> sum;
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
 
int solve(int n){
	int ans=0;
	for(int i=0;pl[i]*pl[i]<=n && i<pl.size();i++){
		if(n%pl[i]==0){
			int count = 0;
			while(n%pl[i]==0){
				count++;
				n/=pl[i];
			}
			ans = max(ans, count);
		}
	}
	if(n>1){
		ans = max(ans, 1);
	}
	return ans;
}
 
int cas, n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fast_sieve(MAX);
	cin >> cas;
	for (int i = 1; i <= cas; i++) {
		cin >> n;
		cout<<solve(n)<<'\n';
	}
}
