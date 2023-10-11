package main

import (
  "os"	
  "bufio"
  "fmt"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func min(x, y int) int {
  if x < y {
      return x
  }
  return y
}
var coins []int
var dp = make([]int, 1001)

func coinChange(coins []int, amount int){
  inf:=100000000
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
}

func main() {
  defer writer.Flush()

  var n, a int
  for i:= 1; i*i <= 1000;i++ {
    coins = append(coins,i*i)
  }
  coinChange(coins, 1000)
  scanf("%d\n", &n);
  for i := 0; i < n; i++ {
  	  scanf("%d\n", &a);
 	  printf("%d\n", dp[a]);
  }
} 