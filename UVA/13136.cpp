#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 MOD = 10;
struct Matriz
{
	vector<vector<int> >M;
	Matriz(int N){
		M.resize(N,vector<int>(N,0));
	}
	friend Matriz operator * (const Matriz &a,const Matriz &b){
		int len = a.M.size();
		Matriz res(len);
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
				for(int k=0;k<len;k++){
					i64 x = ((i64)a.M[i][k]*(i64)b.M[k][j])%MOD;
					res.M[i][j] = (res.M[i][j]+x)%MOD;
				}
		return res;
	}

};
Matriz identity(int N){
	Matriz res(N);
	for(int i=0;i<N;i++)
		res.M[i][i]=1;
	return res;
}

Matriz POW(Matriz a,i64 b){
	Matriz res = identity(a.M.size());
	while(b){
		if(b&1){
			res = res*a;
		}
		b>>=1;
		a = a*a;
	}
	return res;
}
void print(Matriz M)
{
	for(int i=0;i<M.M.size();i++){
		for(int j=0;j<M.M.size();j++)
			cout<<M.M[i][j]<<" ";
		cout<<"\n";
	}
}
int mul(vector<int>A, int B[]){
	int ans = 0;
	for(int i=0;i<4;i++){
	  ans = (ans + A[i]*B[i])%10;
	}

	return ans;
}

int n,a,b,c,cas;
i64 k;
int arr[4];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>cas;
	Matriz N(4);
	while(cas--){
		cin>>k>>arr[1]>>arr[2]>>arr[3];
		N.M[0][0]=1,N.M[0][1]=8,N.M[0][2]=-6,N.M[0][3]=-7;
		N.M[1][0]=0,N.M[1][1]=4,N.M[1][2]=-3,N.M[1][3]=-3;
		N.M[2][0]=0,N.M[2][1]=5,N.M[2][2]=-4,N.M[2][3]=-4;
		N.M[3][0]=0,N.M[3][1]=-1,N.M[3][2]=1,N.M[3][3]=0;
		int ans=0;
		if(k == 0)
			ans = (arr[3]+arr[1]+arr[2])%10;
		else{
			Matriz R = POW(N,k%15);
			ans = mul(R.M[0],arr);
		}

		cout<<(ans+10)%10<<'\n';
	}
	return 0;
}
