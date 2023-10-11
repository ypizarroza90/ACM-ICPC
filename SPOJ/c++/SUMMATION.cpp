#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int i64;
const int N = 1001;
const int MOD = 100000007;
i64 sum1;

i64 modpow(i64 a, i64 b, int mod){
	i64 ans = 1LL;
	while(b){
		if(b&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}

	return ans;
}

int cas, n;
i64 f[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	for(int j = 1;j<=cas; j++){
		cin>>n;
		sum1 =0;
		for(int i=0;i<n;i++){
			cin>>f[i];
			f[i] %= MOD;
			sum1 = (sum1+f[i])%MOD;
		}
		cout<<sum1<<endl;
		cout<<"Case "<<j<<": "<<(modpow(2, n-1, MOD)*sum1)%MOD<<endl;
	}
	return 0;
}
