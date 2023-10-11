#include <bits/stdc++.h>
#define MAX 1000010
using namespace std;
typedef long long i64;
i64 dataMul[MAX],DataAdd[MAX];
void internal(int at,i64 mul,i64 add){
  for(int i=at;i<MAX;i=(i|(i+1))){
    dataMul[i]+=mul;
    DataAdd[i]+=add;
  }
}
void update(int left,i64 right,i64 it){
  internal(left,it,-it*(left-1));
  internal(right,-it,it*right);
}
i64 querysum(int x){
  i64 mul=0,add=0,start=x;
  for(int i=x;i>=0;i=(i&(i+1))-1){
    mul+=dataMul[i];
    add+=DataAdd[i];
  }
  return mul*start+add;
}
i64 query(int x,int y){
  return querysum(y)-querysum(x-1);
}

int N,M,W,x,y,op,val,cas;
int main() {
    memset(DataAdd,0,sizeof(DataAdd));
    memset(dataMul,0,sizeof(dataMul));
	scanf("%d%d%d",&N,&M,&W);
    for(int i=0;i<N;i++){
      scanf("%d%d",&x,&y);
      update(x,y,1);
    }
    while(M--){
    	scanf("%d",&x);
    	printf("%lld\n",query(x,x));
    }

  return 0;
}

