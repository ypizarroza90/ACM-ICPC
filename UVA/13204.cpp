#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1000000
#define MOD 1000000007
typedef long long int i64;
using namespace std;
int n;
i64 facto[MAX+1], ans;
int main() {
	facto[0] = 1;
	for(int i=1;i<=MAX;i++){
		facto[i] = (facto[i-1]*i)%MOD;
	}
	while(cin>>n){
		if(n&1)
			ans = ((facto[(n-1)/2]*facto[(n-1)/2]) % MOD * n) % MOD;
		else
			ans = (facto[n/2]*facto[n/2]) % MOD;
		cout<<ans<<endl;
	}
	return 0;
}

