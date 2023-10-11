import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;
 
public class Main {
	 
	final static InputStreamReader istream = new InputStreamReader(System.in);
	final static BufferedReader stdin = new BufferedReader(istream);
        static BigInteger ZERO =BigInteger.ZERO;
        static BigInteger ONE =BigInteger.ONE;
         static BigInteger TWO =BigInteger.valueOf(2);
        public static  BigInteger sqrt(BigInteger num){
            BigInteger l=BigInteger.ONE;
            BigInteger r=num,mid;
            while(r.subtract(l).compareTo(ONE)>0){
                mid=(l.add(r)).divide(TWO);
                if((mid.multiply(mid)).compareTo(num)>0)
                    r=mid;
                else if((mid.multiply(mid)).compareTo(num)==0)
                    return mid;
                else
                    l=mid;
            }
            return l;
        }
	public static  void solve(BigInteger N,BigInteger K){
            BigInteger a,b,k;
            k=sqrt(N.multiply(K));
            a=b=k;
            while(true){
                if(N.mod(a).equals(ZERO)&& !N.equals(a) && !a.equals(ONE)){
                    b=N.divide(a);
                    break;
                }
                if(N.mod(b).equals(ZERO)&& !N.equals(b) && !b.equals(ONE)){
                    a=N.divide(b);
                    break;
                }
                a=a.subtract(ONE);
                b=b.add(ONE);
            }
            if(a.compareTo(b)>0){
                k=a;
                a=b;
                b=k;
            }
            System.out.println(a+" * "+b);
        }
	public static void main(String[] args) throws Exception {
		String s;
		BigInteger n,k;
		StringTokenizer st;
             	while((s=stdin.readLine())!=null) {
			st=new StringTokenizer(s);
                        n=new BigInteger(st.nextToken());
                        k=new BigInteger(st.nextToken());
                        solve(n, k);
		}
	}
}