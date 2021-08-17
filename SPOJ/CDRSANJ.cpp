#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> V(100001,-1);

int solve(int N){
	if(N <= 2) return N;
	if(V[N] != -1) return V[N];
	if(N%2 == 0) return V[N]= 2 + solve(N/2);
	return 0;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	cout<<solve(N)<<'\n';
	return 0;
}
