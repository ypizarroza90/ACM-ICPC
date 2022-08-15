#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
typedef long long i64;
i64 M[1026][1026];
int n;
i64 query(int x,int y){
	i64 sum=0;
	 int y1;
	 while(x>0){
		 y1=y;
		 while(y1>0){
			 sum+=M[x][y1];
			 y1-=(y1&-y1);
 
		 }
		 x-=(x&-x);
	 }
	return sum;
}
i64 query2(int x,int y,int x2,int y2){
	i64 P=(query(x2,y2)-query(x-1,y2)-query(x2,y-1)+query(x-1,y-1));
	return P;
}
i64 queryf(int x,int y){
	i64 l=query2(x,y,x,y);
	return l;
}
void update(int i,int j,int val){
	  int y1;
	  int
	  v=val-queryf(i,j);
	  while(i<=n){
		  y1=j;
		  while(y1<=n){
			  M[i][y1]+=v;
			  y1+=(y1&-y1);
		  }
		  i+=(i&-i);
	  }
}
int cas,x,y,z,t;
char op[4];
int main(){
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);++n;

		memset(M,0,sizeof(M));
		while(1){
		scanf("%s",op);
		if(strcmp(op,"END")==0)break;
		if(strcmp(op,"SET")==0){
			scanf("%d%d%d",&x,&y,&z);++x,++y;
			update(x,y,z);
		}
		else{
			scanf("%d%d%d%d",&x,&y,&z,&t);
			++x,++y,++z,++t;
			printf("%lld\n",query2(x,y,z,t));
		}
		}
		printf("\n");
	}
	return 0;
}
