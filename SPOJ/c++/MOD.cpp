#include <bits/stdc++.h>
typedef long long int i64;
typedef __int128 bigint;
using namespace std;
#define endl '\n'
int solve(int a, int b, int m) {
	a %= m, b %= m;
	int k = 1, add = 0, g;
	while ((g = __gcd(a, m)) > 1) {
		if (b == k)
			return add;
		if (b % g)
			return -1;
		b /= g, m /= g, ++add;
		k = (k * 1ll * a / g) % m;
	}

	int n = sqrt(m) + 1;
	int an = 1;
	for (int i = 0; i < n; ++i)
		an = (an * 1ll * a) % m;

	unordered_map<int, int> vals;
	for (int q = 0, cur = b; q <= n; ++q) {
		vals[cur] = q;
		cur = (cur * 1ll * a) % m;
	}

	for (int p = 1, cur = k; p <= n; ++p) {
		cur = (cur * 1ll * an) % m;
		if (vals.count(cur)) {
			int ans = n * p - vals[cur] + add;
			return ans;
		}
	}
	return -1;
}
int a,z,k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>a>>z>>k, a, z, k){
	int ans = solve(a, k, z);
	if (ans != -1)
		cout<<ans<<endl;
	else
		cout<<"No Solution"<<endl;
	}
}

