#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int cas, n, m;
string medicine[3001];
int values[3001];
set< pair<int,int> > store;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>medicine[i]>>values[i];
			auto pii = make_pair(values[i], i);
			store.insert(pii);
		}
		for(int i=0;i<m;i++){
			auto pii = *store.begin();
			store.erase(pii);
			cout<< pii.first <<' '<<medicine[pii.second]<<endl;
			store.insert(make_pair(values[pii.second]+pii.first, pii.second));
		}
		store.clear();

	}
	return 0;
}

