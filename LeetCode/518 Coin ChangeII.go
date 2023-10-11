func change(amount int, coins []int) int {
    dp:= make([]int, amount+1)
    dp[0] = 1
    for j:=0;j<len(coins);j++{
      for i:=coins[j];i<=amount;i++{
            dp[i] += dp[i-coins[j]]
        }
    }
    return dp[amount]
}

