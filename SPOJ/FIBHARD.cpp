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
#define mod 998244353;
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

int cas;
i64 N,b;
string cad;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>cas;
	while(cas--){
		cin>>cad;
		N = 0;
		for(unsigned int i= 0; i < cad.size(); i++){
			N = N * 10 + cad[i]-'0';
			N %= 1996488708;
		}
		i64 M[2][2] ={{1,1},{1,0}};
		POW(M,N);
		b = ans[0][1];
		cout<<b<<endl;
	}
	return 0;
}


