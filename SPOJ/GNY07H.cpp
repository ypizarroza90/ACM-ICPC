#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <set>
#include <map>
using namespace std;
#define ALL 20010
#define SHIFT 10005
 
typedef long long Long;
 
long T[16][16];
 
void rec(int id, int b, int nb, set<int> &a){
	if(id == 4){
		a.insert(nb);
		return;
	}
	if(b & (1<<id))rec(id+1, b, nb, a);
	else{
		rec(id+1, b, nb | (1<<id), a); // hor
		if(id+1 < 4 && (b & (1<<(id+1))) == 0){
			rec(id+2, b, nb, a);
		}
	}
}
void MUL(long M[16][16],long N[16][16]){
	long R[16][16];
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			R[i][j] = 0;
			for(int k=0;k<16;k++){
				R[i][j] = (R[i][j]+ 1LL*M[i][k]*N[k][j]);
			}
		}
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			M[i][j]=R[i][j];
 
		}
	}
}
 
void POW(long M[16][16],Long P){
	long R[16][16];
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			R[i][j]=0;
		}
		R[i][i]=1;
	}
	while(P){
		if(P&1){
			MUL(R,M);
		}
		P>>=1;
		MUL(M,M);
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			M[i][j] = R[i][j];
		}
	}
}
 
int main() {
	Long N,cas;
	cin>>cas;
	for(int i=1;i<=cas;i++){
		cin >> N;
		memset(T,0,sizeof(T));
		for (int i = 0; i < (1<<4); ++i) {
 
			set<int> a;
			rec(0, i, 0, a);
			for(set<int>::iterator n= a.begin();n!=a.end();n++){
				T[i][*n] = 1;
			}
 
		}
		POW(T, N);
		cout <<i<<" "<<T[0][0] << endl;
	}
 
}