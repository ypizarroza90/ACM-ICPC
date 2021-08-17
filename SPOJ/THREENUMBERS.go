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

func gcd(a int64, b int64) int64{
	if b >0{ 
    return gcd(b, a % b)
     }else { 
      return a
  }
}

func main() {
  defer writer.Flush()
  var cas int;
  var a,b,n int64;
  scanf("%d\n", &cas);
  for i := 0; i < cas; i++ {
  	scanf("%v%v%v\n", &a,&b,&n);
    gcd := gcd(a,b);
  	ab := (a*b)/ gcd;
  	lo , hi := int64(0), int64(a * n);
  	for lo < hi {
  		mid := (lo + hi -1 ) >>1;
  		val := mid / a + mid / b - mid / ab;
  		if val >= n {
  			hi = mid
  		}else{
  			lo = mid + 1
  		}
  	}
  	printf("%v\n", lo);
  }
} 