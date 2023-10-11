#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int modpow(int a, int b, int MOD){
	int res = 1;
	while(b){
		if(b&1) res = (res * a) % MOD;
		a = (a*a) % MOD;
		b >>= 1;
	}
	return res;
}

string a,b;
int B,N;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b;
	B = 0, N = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		B = (B * 10 + a[i]-'0') % 9;
	}
	for (int i = 0; i < b.size(); ++i)
	{
		N = (N * 10 + b[i]-'0') % 6;
	}
	if(B == 0) B = 9;
	if(N == 0) N = 6;
	int ans = modpow(B, N, 9);
	if(ans == 0) ans = 9;
	cout<< ans <<endl;
}
