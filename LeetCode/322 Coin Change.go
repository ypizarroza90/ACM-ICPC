func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func coinChange(coins []int, amount int) int {
    inf:=100000000
    dp:= make([]int, amount+1)
    ans := -1
    for i:=1;i<amount+1;i++{
        dp[i] = inf
    }
    for i:=0;i<len(dp);i++{
        for j:=0;j<len(coins);j++{
            if i - coins[j] >= 0{
                dp[i] = min(dp[i], dp[i-coins[j]]+1)
            }
        }
    }
    if dp[amount] != inf {
        ans = dp[amount]
    }
    return ans
}
