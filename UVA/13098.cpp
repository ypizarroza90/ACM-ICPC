#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e+7 + 15;
int M[MAXN];
vector<int>triangulars;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(M, 0xf, sizeof(M));
	M[0] = 0;
	for (int i = 1,x=1; x <= MAXN; i++,x+=i)
		triangulars.push_back(x);
	for (int i = 0; i < triangulars.size(); i++)
		M[triangulars[i]] = 1;
	for (int i = 0; i < triangulars.size(); i++) {
		for (int j = i; j < triangulars.size() && triangulars[i]+triangulars[j] < MAXN; j++)
			M[triangulars[i]+triangulars[j]] = min(M[triangulars[i]+triangulars[j]], 2);
	}
	int n;
	while (cin>>n) {
		if (M[n] <= 2)
			cout<<M[n]<<"\n";
		else
			cout<<3<<"\n";
	}
	return 0;
}
