#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include<iostream>
#include <sstream>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
const int MAX= 1500;
i64 M[MAX][MAX];
int n,u,q,x,y,val,op,x2,y2;
i64 querry(int x,int y){
	i64 sum=0;
	int y1;
	while(x>0){
		y1=y;
		while(y1>0){
			sum=(M[x][y1]+sum);
			y1-=(y1&-y1);
		}
		x-=(x&-x);
	}
	return sum;
}
i64 querr2(int x,int y,int x2,int y2){
	i64 P=(querry(x2,y2)-querry(x-1,y2)-querry(x2,y-1)+querry(x-1,y-1));
	return P;
}
i64 queryf(int x,int y){
	return querr2(x,y,x,y);
}
void update(int x,int y,int val){
	int y1;
	int v=val;
	while(x<=n){
		y1=y;
		while(y1<=n){
			M[x][y1]=(v+M[x][y1]);
			y1+=(y1&-y1);
		}
		x+=(x&-x);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>op){
		if(op==3)return 0;
		else if(op==0){
			cin>>n;
			memset(M,0,sizeof(M));
		}
		else if(op==1){
			cin>>x>>y>>val;x++,y++;
			update(x,y,val);
		}
		else{
			cin>>x>>y>>x2>>y2;
			x++,y++,y2++,x2++;
			cout<<querr2(x,y,x2,y2)<<"\n";
		}
 
	}
	return 0;