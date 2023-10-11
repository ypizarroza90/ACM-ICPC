#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAX 10000001
#define mod 1000000007
vector<int> D;
int cas,n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	D = {1,0};
	for(int i=2;i<MAX;i++){
		D.push_back(((i64)(i-1)*(D[i-1]+D[i-2]))%mod);
	}
	cin>>cas;
	while(cas--){
		cin>>n;
		cout<<D[n]<<'\n';
	}

}

