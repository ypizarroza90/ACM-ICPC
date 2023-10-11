#include <bits/stdc++.h>
#define i64 long long
using namespace std;
string cad;
const int one = 252,two = 525;
int cas,_a,_b;
bool a,b;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>cad;
		for(int i=0;cad[i];i++){
			_a = (_a*10+cad[i]-'0')%one;
			_b = (_b*10+cad[i]-'0')%two;
		}
		a = _a != 0,b = _b != 0;
		cout<<(a?"No":"Yes")<<" "<<(b?"No":"Yes")<<"\n";
		_a = _b = 0;
	}
	return 0;
}