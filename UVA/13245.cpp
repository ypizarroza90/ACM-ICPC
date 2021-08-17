#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl '\n'
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 5001

int flag[MAX>>3],primes[MAX>>2],len;
int dp[5009];

void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<=MAX;j+=k)
				isc(j);
	}
	primes[(k=0)++]=1, primes[k++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			primes[k++]=i;
	len=k-1;
}

int cas, cnt;
int N, K;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();

	cin>>cas;
	while(cas--){
		cin>>N>>K;
		memset(dp,63, sizeof(dp));
		dp[0] = 0;
		for(int i=0;i<N; i++){
			for(int j=primes[i];j<=K;j++)
				dp[j] = min(dp[j],dp[j-primes[i]]+1);
		}
		cout<<dp[K]<<endl;
	}

}
 
