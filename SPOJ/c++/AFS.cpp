#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int N,cas;
vector<long long int> V(MAX + 9,1);
void solve() {
	for (int i = 2; i <= MAX>>1; i++) {
			for (int j = 2 * i; j <= MAX; j += i){
				V[j] += i;
			}
	}
	V[0]=V[1] = 0;
	for (int i = 2; i<= MAX; i++)
		V[i] = V[i-1]+V[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	cin >> cas;
	while (cas--) {
		cin >> N;
		cout << V[N] << '\n';
	}
	return 0;
}
 
