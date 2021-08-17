#include <bits/stdc++.h>

using namespace std;
int cas,N;
long long int K,x;
vector<long long int> V;

pair<long long int,int> solve(vector<long long int> V, long long int K){
	long long int sum,tmpsum;
	int size,tmpsize,pos;
	sum = tmpsum = 0;
	size= tmpsize = pos = 0;
	for(int i=0;i<V.size();i++){
		if(tmpsum + V[i] <= K){
			tmpsum += V[i];
			tmpsize++;
		}else{
			while(tmpsum + V[i] > K){
						tmpsum -= V[pos];
						tmpsize--;
						pos++;
			}
			tmpsum += V[i];
			tmpsize++;
		}
		if(tmpsize > size ||(tmpsize == size && tmpsum < sum)){
			size = tmpsize; sum = tmpsum;
		}
	}

	return make_pair(sum,size);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>N>>K;
		for(int i=0;i<N;i++){
			cin>>x;
			V.push_back(x);
		}
		auto ans = solve(V, K);
		cout<<ans.first<<' '<<ans.second<<'\n';
		V.clear();
	}
	return 0;
}
 
