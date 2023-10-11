#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <set>
#include <map>
using namespace std;
 
long long n;
int main() {
	while(cin>>n, n){
		n++;
		cout<<n*(3*n-1)/2<<'\n';
	}
 
}
