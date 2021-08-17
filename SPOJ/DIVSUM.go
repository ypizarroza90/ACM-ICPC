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
func ifc(x int) int{ return flag[x>>6]&(1<<uint8((x>>1)&31)) }
func isc(x int){ flag[x>>6]|=(1<<uint8((x>>1)&31)) }

const MAX = 1000001;
var primes [MAX>>2] int;
var flag [MAX>>6+10]int;
var len int;

func pow(p int64, n int) int64{
	var a int64 = 1;
	for n > 0 {
		if n % 2 == 1{
			a = a * p;
		}
		p = p * p;
		n = n >> 1;
	}
	return a;
}


func criba() {
	for i := 3; i*i < MAX; i+=2 {
		if ifc(i) == 0{
			for j := i*i; j < MAX; j+=i<<1 {
				isc(j)
			}
		}
	}
	k := 0
	primes[k] = 2;k++;
	for i := 3; i < MAX; i+=2 {
		if ifc(i) == 0{
			primes[k] = i;k++;
		}
	}
	len = k-1
}

func solve(N int64) int64{
	var ans int64 = 1;
	for i := 0; int64(primes[i] * primes[i]) <= N && i < len; i++ {
		if N % int64(primes[i]) == 0{
			cnt := 0;
			for N % int64(primes[i]) == 0 {
				cnt += 1;
				N /= int64(primes[i]);
			}
			ans *= (pow(int64(primes[i]), cnt +1) -1)/ int64(primes[i] - 1)
		}
	}
	if N > 1 { 	ans *= (N * N -1 ) / (N - 1); }
	return ans;
}


func main() {
  defer writer.Flush()
  criba()
  var n int;
  var N int64;
  scanf("%d\n", &n);
  for i := 0; i < n; i++ {
  	scanf("%v\n", &N);
  	printf("%v\n", solve(N) - N);
  }
} 
