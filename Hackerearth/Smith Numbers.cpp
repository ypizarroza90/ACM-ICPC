#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define endl '\n'
vector<int>smith(MAX,0);
int sum_digits(int n){
	int ans = 0;
	while(n){
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
void solve(){
	vector<int>max_div(MAX,0);
	vector<int>sum_prime(MAX,0);
	for(int i=2;i<MAX;i++){
		if(!max_div[i]){
			max_div[i] = i;
			sum_prime[i] = sum_digits(i);
			for(int j=2*i;j<MAX;j+=i){
				max_div[j] = i;
				sum_prime[j] = sum_prime[j/i] + sum_prime[i];
			}
		}
	}
	for(int i=2;i<MAX;i++)
		smith[i] = (sum_digits(i)==sum_prime[i]) + smith[i-1];
}
int T,A,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	cin>>T;
	while(T--){
		cin>>A>>B;
		cout<<smith[B]-smith[A-1]<<endl;
	}
}

