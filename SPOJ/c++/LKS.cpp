    #include <bits/stdc++.h>
    using namespace std;
    int knapSack(int W, int wt[], int val[], int n)
    {
        int dp[W + 1];
        memset(dp, 0, sizeof(dp));
     
        for (int i = 1; i < n + 1; i++) {
            for (int w = W; w >= 0; w--) {
     
                if (wt[i - 1] <= w)
                    dp[w] = max(dp[w],
                                dp[w - wt[i - 1]] + val[i - 1]);
            }
        }
        return dp[W];
    }
    int n,k;
    int weight[501],profit[501];
    int main()
    {
     
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	cin>>n>>k;
    	for(int i=0;i<k;i++){
    		cin>>profit[i]>>weight[i];
    	}
    	cout<<knapSack(n, weight, profit, k)<<'\n';
    	return 0;
    }
     