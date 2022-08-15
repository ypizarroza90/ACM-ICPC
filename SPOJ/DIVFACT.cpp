#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define  MAX 100000001
using namespace std;
typedef long long i64;
int flag[MAX>>6],primes[MAX>>3],len;
i64 MOD = 1000000007;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<=MAX;j+=k)
				isc(j);
	}
	primes[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			primes[k++]=i;
	len=k-1;
}

i64 divpow(int N,int pow){
	i64 res=0;
	while(N){
		res+=N/pow;
		N/=pow;
	}
	return res;
}

i64 multiply(i64 a,i64 b, i64 mod){
 i64 rx=0,sx=0;
  for (int bx=0; b>>bx>0; ++bx){
    sx+=(bx)?sx:a;
    if(sx>=mod) sx-=mod;
    rx+=((b>>bx)&1)?sx:0;
    if(rx>=mod) rx-=mod;
  }
  return rx;
}

i64 modpow(i64 N, i64 M, i64 MOD){
	i64 ans = 1;
	while(M){
		if (M&1) ans = (ans * N) % MOD;
		N = (N*N) % MOD;
		M >>= 1;
	}
	return ans;
}

int cas;
int N,dim;
i64 mul;
int main() {
	  criba();
	  scanf("%d",&cas);
	  while(cas--){
		  scanf("%d",&N);
		  mul=1LL;
		  for(int i=0;primes[i]*primes[i]<=N;i++){
			  mul=multiply(mul,divpow(N,primes[i])+1,MOD);
		  }
		  i64 root = sqrt(N);
		  auto it = upper_bound(primes, primes+len, root);
		  	  if(root*root<N) root++;
		  for (int i = root-1; i > 0; i--)
		  {
		  	auto bt = upper_bound(primes, primes+len, N/i);
		  	if(*bt > *it){
		  		i64 tmp = modpow(i+1,bt-it,MOD);
		  		mul = multiply(mul,tmp,MOD);
		  		it = bt;
		  	}
		  }

		 printf("%lld\n",mul);
	  }
	return 0;
}

