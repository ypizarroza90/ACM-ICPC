#include<bits/stdc++.h>
#define MAX 1000009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
#define i64 long long
int flag[MAX>>6],prime[MAX>>3],len;
int F[MAX>>3],D[MAX>>3],d;
void criba()
{
	int i,j,k;
	for(i=3;i*i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len=k;
}
int factorize(int N,int f[]){
	int d=0;
	for(int i=0;prime[i]*prime[i]<=N && i<len;i++){
		while(N%prime[i]==0)
		{
			f[d++]=prime[i];
			N/=prime[i];
		}
	}
	if(N>1)f[d++]=N;
	return d;
}
void div(int cur,int f[],int s,int e)
{
	if(s==e)D[d++]=cur;
	else{
		int m;
		for( m=s+1;m<e && f[m]==f[s];m++);
			for(int i=s;i<=m;i++)
			{
				div(cur,f,m,e);
				cur*=f[s];
		}
	}
}
int N,x,y;
i64 sum;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>x;
		sum = 0;
		int E=factorize(x,F);
		d=0;
		div(1,F,0,E);
		for(int j=0;j<d;j++){
			for(int k=j+1;k<d;k++)
				sum+=(D[j]*(i64)D[k]);
		}
		cout<<sum<<"\n";
	}

}
