//============================================================================
// Name        : online.cpp
// Author      : Anth@x
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
#define mod 1000000007;
#define endl '\n'
void MULT(i64 A[2][2],i64 B[2][2],i64 C[2][2])
{
	i64 aux[2][2];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			aux[i][j] = 0;
			for(int k=0;k<2;k++){
				aux[i][j]=(aux[i][j]+A[i][k]*B[k][j])%mod;
			}
		}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			C[i][j]=aux[i][j];

}
i64 ans[2][2];
void POW(i64 A[2][2],i64 K)
{
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			ans[i][j]=(i==j);
	while(K)
	{
		if(K&1)
			MULT(ans,A,ans);
		K>>=1;
		MULT(A,A,A);
	}
}
i64 fibos[76];
int kth_non_fibo(int k){
	int lo = 1, hi = mod;
	int ans = hi, mid, sum;
	while (lo <= hi){
		mid = (lo + hi) >> 1;
		sum = 0;
		for(int i=1;i<75;i++)
			if(fibos[i] <= mid)
				sum += 1;
			else
				break;
		if (mid - sum >= k){
			ans = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	return ans;
}

i64 pow(i64 A,i64 K)
{
	i64 ans = 1LL;
	while(K)
	{
		if(K&1)
			ans = (ans * A) % mod;
		K>>=1;
		A = (A * A) % mod;
	}
	return ans;
}
i64 N,a,b;
int cas;
int main()
{
	ios_base::sync_with_stdio(0);
	fibos[0] =1, fibos[1] = 1;
	for(int i=2;i<=75;i++)
		fibos[i] = fibos[i-2] + fibos[i-1];

	cin>>cas;
	while(cas--){
		cin>>N;
		i64 M[2][2] ={{1,1},{1,0}};
		POW(M,N);
		b = ans[0][1];
		a = kth_non_fibo(N);
		cout<<pow(a,b)<<endl;
	}
	return 0;
}


