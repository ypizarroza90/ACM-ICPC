#include <bits/stdc++.h>
using namespace std;
string line;
int ret;
int main() {
	while(cin>>line,line!="0"){
		ret=0;
		for(char i:line){
			ret =(ret*10+i-48)%17;
		}
		cout<<(ret == 0?'1':'0')<<'\n';
	}
	return 0;
}

