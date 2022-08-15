#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
typedef long long i64;
i64 T[MAX];
int input[MAX],C[MAX];
void add(int i,int x){
	for(;i<MAX;i+=(i&-i))
		T[i]+=x;
}
i64 sum(int i){
	i64 sum=0;
	for(;i;i-=(i&-i))
		sum+=T[i];
	return sum;
}
int cas,x, pos;
i64 res;
int main() {

	scanf("%d",&cas);
	while(cas--){
		memset(T,0,sizeof(T));res=0, pos=0;
		scanf("%d",&x);
		for(int i=0;i<x;i++){
			scanf("%d",&input[i]);
			C[i] = input[i];
		}
		sort(input, input+x);
		for(int i=0;i<x;i++){
			C[i] = lower_bound(input, input+x, C[i]) - input;
		}
		for(int i=0;i<x;i++){
			res+=sum(C[i]);
			add(C[i]+1,input[C[i]]);
		}
		printf("%lld\n",res);
	}
    return 0;
}
