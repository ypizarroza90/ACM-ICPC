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

const MAX = 2*1000009;
var pivot int = 100001;
var tree [MAX] int64;

func update(pos int, val int64){
	for i:=pos; i<MAX; i += (i&-i) {
		tree[i] += val;
	}
}

func get(pos int) int64 {
	var sum int64 = 0;
	var i int = pos;
	for i > 0 {
		sum += tree[i];
		i -= (i&-i);
	}
	return sum;
}

func query(a int, b int) int64 {
	var ans int64 = get(b) - get(a-1);
	return ans;
}

func main() {
  defer writer.Flush()
  
  var n, a,b, op int;
  var x int64;
  scanf("%d\n", &n);
  for i:=0;i<n;i++ {
	scanf("%v", &x);
	update(i+pivot, x);
  }
  scanf("\n");
  scanf("%d\n", &n);
  for i:=0;i<n;i++ {
 	scanf("%d",&op);
	if op == 1 {
		scanf("%d %d\n",&a, &b);
		a-=1;b-=1;
		var ans int64 = query(a+pivot, b+pivot);
		printf("%v\n", ans);
	} else {
		scanf("%v\n",&x);
		pivot -= 1;
		update(pivot,x);
	}
  }
} 
