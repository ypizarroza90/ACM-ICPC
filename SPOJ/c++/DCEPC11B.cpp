#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAX 10000001
i64 modpow(i64 a, i64 b, i64 mod){
	i64 ans = 1LL;
	while(b){
		if(b&1) ans = (a*ans) % mod;
		a = (a*a) % mod;
		b>>=1;
	}
 
	return ans;
}
int cas,n,p;
i64 res;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		res = -1;
		cin>>n>>p;
		if(n>=p){
			cout<<0<<'\n';
		}else{
			for(int i=n+1;i<p;i++)
				res = (res * modpow(i, p-2, p))%p;
			cout<<res+p<<'\n';
		}
	}
 
}
