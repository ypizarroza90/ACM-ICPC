#include <bits/stdc++.h>
using namespace std;
#define i64 long long
 
i64 digits_in_factorial(i64 n) {
	if (n == 0)
		return 1;
	return (long long int) (((log(6.283185307179586 * n) / 2.0
			+ n * (log(n) - 1)) / 2.302585092994046) + 1);
}
int cas, n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> cas;
	while (cas--) {
		cin >> n;
		i64 lo = 1, hi = 1e9+1, mid;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;
			i64 dig = digits_in_factorial(mid);
			if(dig == n || lo == mid || hi == mid)
				break;
			else if (dig > n)
				hi = mid;
			else
				lo = mid;
		}
		while (digits_in_factorial(hi) > n)
			hi--;
		while (digits_in_factorial(hi) <= n)
					hi++;
		cout << hi-1 << '\n';
	}
 
}
