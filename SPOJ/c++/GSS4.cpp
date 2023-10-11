#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAX 1000009
long long int tree[MAX];
long long int input[MAX];
int N,Q, op, cas;
long long int x,y;
void update(int pos, long long int val){
	for(int i=pos;i<MAX; i+=i&-i)
		tree[i] += val;
}

long long int get(int pos){
	int i=pos;
	long long  int sum = 0;
	while(i>0){
		sum += tree[i];
		i -= i&-i;
	}

	return sum;
}
long long int  query(int x, int y){
	return get(y)-get(x-1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cas = 1;
	while(cin>>N){
		set< int > valids;
		fill(tree, tree+MAX, 0LL);
		for(int i=1;i<=N;i++){
			cin>>input[i];
			if(input[i]>1) valids.insert(i);
			update(i, input[i]);
		}
		cin>>Q;
		cout<<"Case #"<<cas<<":\n";
		while(Q--){
			cin>>op>>x>>y;
			if (x > y) {
				swap(x, y);
			}
			if(!op){
				set<int> invalids;
				for(set<int>::iterator it=valids.lower_bound(x); it!=valids.end() && *it <= y; it++){
					update(*it, -input[*it]);
					input[*it] = (long long)sqrtl(1.0 * input[*it]);
					if(input[*it] == 1) invalids.insert(*it);
					update(*it, input[*it]);
				}
				for(auto i: invalids) valids.erase(i);
				invalids.clear();
			}else{
				cout<<query(x,y)<<endl;
			}
		}
		valids.clear();
		cas++;
		cout<<endl;
	}
	return 0;
}

