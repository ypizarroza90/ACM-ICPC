func countPrimes(n int) int {
    ans := 0
    prime := make([]bool, n)
    for i:=2;i*i<n;i++{
        if prime[i] == false{
            for j:= 2*i;j<n;j+=i{
                prime[j]=true
            }
        }
    }
    for i:=2;i<n;i++{
        if prime[i] == false{
            ans++;
        }
    }
    return ans;
}
