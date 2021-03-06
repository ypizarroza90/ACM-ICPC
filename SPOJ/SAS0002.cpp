#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define  i64 long long

inline i64 mod_mul(i64 x,i64 y,i64 n){
	if(!x)
		return 0;
	return (((x&1)*y)%n+(mod_mul(x>>1,y,n)<<1)%n)%n;
}
inline int rand32(){
	return (rand()|rand()<<16)&0x7fffffff;
}
inline i64 myrand(){
	return ((i64)rand32()|
			(i64)rand32()<<32)&0x7fffffffffffffffLL;
}
i64 mod_exp(i64 a,i64 x,i64 n){
	i64 ret=1;
	while(x){
		if(x&1) ret=mod_mul(ret,a,n);
		a=mod_mul(a,a,n);
		x>>=1;
	}
	return ret;
}
i64 gcd(i64 x,i64 y){
	i64 q;
	while(1){
		if(!y) return abs(x);
		q=x,x=y,y=q%y;
	}
}
int primes[]={2,3,5,7,11,13,17,19,23,29,31};
bool fermat(i64 N){
	if ( N < 2 || ( N > 2 && !( N % 2 ) ) )
	            return false;

	for(int i=0;i<11 && primes[i] < N;i++){
		if(mod_exp(primes[i],N-1,N)!= 1LL)
			return 0;
	}
	return 1;
}
i64 func(i64 x,i64 n){
	return (mod_mul(x,x,n)+1)%n;
}
i64 Pollard(i64 n){
	i64 i,x,y,p;
	if(fermat(n))
		return n;
	if(!(n&1))
		return 2;
	for(i=1;i<20;i++){
		x=i;
		y=func(x,n);
		p=gcd(y-x,n);
		while(p==1){
			x=func(x,n);
			y=func(func(y,n),n);
			p=gcd((y-x+n)%n,n)%n;
		}
		if(p==0||p==n)
			continue;
		return p;
	}
}
unordered_map<i64,int>ans;
void factor(i64 n){
	i64 x;
	x=Pollard(n);
	if(x==n){
		ans[x]++;
		return;
	}
	factor(x);
	factor(n/x);
}
int main(){

	srand(0x12345);
	i64 num,answ;
	int cas;
	scanf("%d",&cas);
	while(cas--){
		scanf("%lld",&num);
		factor(num);
		int divs = 1;
		for (unordered_map<i64,int>::iterator i = ans.begin(); i != ans.end(); ++i)
		{
			divs *= (i->second+1);
		}
		if(divs & 1){
			i64 sq = sqrt(num);
			while( sq*sq <= num) sq++;
			while(sq*sq>num)sq--;
			answ = mod_exp(sq,divs,MOD);
		}else{
			answ = mod_exp(num,divs/2,MOD);
		}
		printf("%lld\n",answ );
		ans.clear();
	}
	return 0;
}

