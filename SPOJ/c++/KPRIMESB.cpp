#include<bits/stdc++.h>
#define MAX 1000001
#define i64 long long
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef pair<i64,int>PI;
int flag[MAX>>6],primes[MAX>>1],len;
void criba(){
	int i,j,k;
	for(i=3;i*i<MAX;i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isc(j);
	primes[(k=0)++]=2;
	for(i=3;i<MAX;i+=2)
		if(!ifc(i))
			primes[k++]=i;
	len = k;
}
vector<PI>comb(vector<int>n){
	int _n = n.size();
	i64 res;
	set<PI>S;
	vector<PI>ans;
	for(int mask=1;mask<(1<<_n);mask++){
		res = 1LL;
		for(int j=0;j<_n;j++){
			if(mask&(1<<j))
				res*=n[j];
		}
		S.insert(make_pair(res,__builtin_popcount(mask)));
	}
	for(auto it=S.begin();it!=S.end();it++)
		ans.push_back(*it);
	return ans;
}
int cas,n,m,x,tmp;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	cin>>cas;
	for(int i=1;i<=cas;i++){
		cin>>n>>m;
		vector<int>a;
		tmp = 0;
		for(int i=0;i<m;i++){
			cin>>x;
			a.push_back(x);
			if(x<=n)tmp++;
		}
		vector<PI>_temp = comb(a);
		int _n = _temp.size();
		i64 ans = n;
		for(int i=0;i<_n;i++){
			if(_temp[i].second&1)
				ans-=n/_temp[i].first;
			else{
				ans+=n/_temp[i].first;
			}
		}
		if(ans) ans--;
		int pos = upper_bound(primes,primes+len,n)-primes;
		cout<<"Case "<<i<<": "<<ans-pos+tmp<<"\n";
	}
	return 0;
}
 
