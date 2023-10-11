    #include <bits/stdc++.h>
    typedef long long int i64;
    typedef __int128 bigint;
    using namespace std;
    #define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
    #define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
    #define  MAX 512
    #define endl '\n'
    int flag[MAX>>6],primes[MAX>>2],len;
    bool dp[20];
    int digits[20];
    void criba(){
    	int i,j,k;
    	for(i=3;i<sqrt(MAX);i+=2){
    		if(!ifc(i))
    			for(j=i*i,k=(i<<1);j<=MAX;j+=k)
    				isc(j);
    	}
    	primes[(k=0)++]=2;
    	for(i=3;i<MAX;i+=2)
    		if(!ifc(i))
    			primes[k++]=i;
    	len=k;
    }

    i64 modpow(i64 a, i64 b, i64 mod){
    	i64 ans = 1LL;
    	a %= mod;
    	while (b) {
    		if (b & 1)
    			ans = (bigint)ans * a % mod;
    		a = (bigint)a * a % mod;
    		b >>= 1;
    	}
    	return ans;
    }

    bool check(i64 n, i64 a, i64 d, int s) {
        i64 x = modpow(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (bigint)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
    };

    bool miller(i64 n){
    	if (n < 4)
    	        return n == 2 || n == 3;

    	int s = 0;
    	i64 d = n - 1;
    	while ((d & 1) == 0) {
    		d >>= 1;
    		s++;
    	}

    	for (int i = 0; i < 5; i++) {
    		int a = 2 + rand() % (n - 3);
    		if (check(n, a, d, s))
    			return false;
    	}
    	return true;
    }

    bool is_prime(i64 n){
    	if (n < 2)
    		return false;

    	if (!(n & 1))
    		 return n == 2;
    	for(int i=0; i<len; i++){
    		if(n % primes[i] == 0)
    			return false;
    		if((i64)primes[i]*primes[i] > n)
    			return true;
    	}
    	return miller(n);
    }

    i64 next_prime(i64 n){
    	n = (n+1) / 2 * 2 + 1;
    	while(!is_prime(n))
    		n += 2;
    	return n;
    }

    i64 solve(i64 n){
    	int m=0;
    	i64 val;
    	while(n){
    		dp[m] = 0;
    		digits[m++] =  n % 10;
    		n /= 10;
    	}
    	n = 0;
    	for(int i=m-1;i>=1; --i){
    		n = n*10 + digits[i];
    		dp[i] |= is_prime(n);
    		if (!dp[i] || !digits[i-1])
    				continue;
    		val = 0;
    		for (int j = i - 1; j >= 0; --j) {
    		      val = val * 10 + digits[j];
    		      dp[j] |= is_prime(val);
    		    }
    	}
    	return dp[0];
    }
    int cas;
    i64 N;
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	criba();
    	cin>>cas;
    	while(cas--){
    		cin>>N;
    		if(N <= 23) cout<<23<<endl;
    		else{
    			N = N + ( N%2 == 0);
    			while(!is_prime(N) || !solve(N))
    				N+=2;
    			cout<<N<<endl;
    		}
    	}
    }

