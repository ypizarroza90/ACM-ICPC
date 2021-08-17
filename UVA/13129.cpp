#include <bits/stdc++.h>
#define MAX 500000
#define MOD 1000000007
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;

class Segment_tree{
public:
	struct node{
		i64 val;
		void init(){};
	}nodes[4*MAX];

	i64 ans;

	void reset(){
		ans = 1LL;
	}

	void lazy(int n){
		nodes[n].val = (nodes[n<<1].val * nodes[n<<1|1].val)%MOD;
	}

	void create(int n, int l,int r,i64 P[]){
		nodes[n].init();
		if(l==r){
			nodes[n].val = P[l];
			return;
		}
		int mid = (l+r)>>1;
		create(n<<1,l,mid,P);
		create(n<<1|1,mid+1,r,P);
		lazy(n);
	}

	void query(int n, int l,int r,int x,int y){
		if(x <= l && y >= r){
			ans *= nodes[n].val;
			ans %= MOD;
			return;
		}
		int mid = (l+r)>>1;
		if(x<=mid)
			query(n<<1,l,mid,x,y);
		if(y > mid)
			query(n<<1|1,mid+1,r,x,y);
	}

}S;
inline i64 mul_mod(i64 a,i64 b,i64 mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  if (mod < int(1e9)) return a * b % mod;
  i64 k = (i64)((long double)a * b / mod);
  i64 res = a * b - k * mod;
  res %= mod;
  if (res < 0) res += mod;
  return res;
}

i64 mod_pow(i64 a, i64 n, i64 m) {
  i64 res = 1;
  for (a %= m; n; n >>= 1) {
    if (n & 1) res = mul_mod(res, a, m);
    a = mul_mod(a, a, m);
  }
  return res;
}
i64 P[MAX];
int n,k,x,y,Q;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>k){
		for(int i=1;i<=n;i++){
			cin>>x;
			P[i] = (mod_pow(k,x,MOD)+1)%MOD;
		}
		cin>>Q;
		S.create(1,1,n,P);
		while(Q--){
			cin>>x>>y;
			S.reset();
			S.query(1,1,n,x,y);
			i64 ans = S.ans-1;
			cout<<(ans+MOD)%MOD<<"\n";
		}
	}
	return 0;
}
