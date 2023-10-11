#include<bits/stdc++.h>
#define MAX 100009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
#define i64 long long
int primes[11];
int T,K,A,B;
unordered_map<i64,int> M;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>K>>T;
for(int i=0;i<K;i++){
	cin>>primes[i];
}
for(int i=1;i<1<<K;i++){
	i64 mul=1LL;
	for(int j=0;j<K;j++){
		if(i&(1<<j)){
			mul *= primes[j];
			if(mul > int(1e9))break;
		}
	}
	if(mul < int(1e9))
		M[mul] = i;
}
while(T--){
	cin>>A>>B;
	A--;
	int ansA=0, ansB=0;
	for(auto &it: M){
		if(__builtin_popcount(it.second)&1){
			ansA += A/it.first;
			ansB += B/it.first;
		}else{
			ansA -= A/it.first;
			ansB -= B/it.first;
		}
	}
	cout<<ansB-ansA<<endl;
}

}
