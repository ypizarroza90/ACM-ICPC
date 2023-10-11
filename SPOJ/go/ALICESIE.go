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

func main() {
  defer writer.Flush()

  var n, a int
  scanf("%d\n", &n);
  for i := 0; i < n; i++ {
  	  scanf("%d\n", &a);
 	  printf("%d\n", (a + 1) >> uint8(1));
  }
} 
