#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1000009
using namespace std;
typedef long long i64;
i64 n;
int MODPOW(i64 b,i64 p, i64 mod){
    int res = 1;
    while(p){
        if(p&1)
            res = (b*res)%mod;
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}
int main(){
    map<int, int> factors{
      {2, 2}, {3, 1}, {167, 1}
    };
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n, n){
        i64 ans = 1;
        for(auto it = factors.begin(); it != factors.end(); it++){
            ans = ans * ((MODPOW(it->first,(it->second * n) + 1, 29)-1) * MODPOW(it->first-1,27,29));
            ans %= 29;
        }
        cout<<ans<<'\n';
    }

}

