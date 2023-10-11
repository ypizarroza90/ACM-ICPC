import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

public class Main {
	
	public static class FastReader{
		final private int BUFFER_SIZE = 65536;
        private InputStream din;   
        private byte[] buffer;     
        private int bufferPointer; 
        private int bytesRead; 
        
        public FastReader(InputStream in) {
            din = in;
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        

        /**
         * Read the next integer from the input stream.
         * @return The next integer.
         * @throws java.io.IOException
         */
        public int nextInt() throws IOException {
            int result = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            while (c >= '0' && c <= '9') {
                result = result * 10 + c - '0';
                c = read();
            }
            if (neg) return -result;
            return result;
        }

        /**
         * Read a line of data from the input stream.
         * @return the next line of data.
         * @throws IOException if an I/O error occurs.
         */
        public String readLine() throws IOException {
            StringBuilder line = new StringBuilder();
            char c;
            while ((c = (char)(read())) != '\n') {
                line.append(c);
            }
            return line.toString();
        }

        /**
         * Read the next byte of data from the input stream.
         * @return the next byte of data, or -1 if the end of the stream is reached.
         * @throws IOException if an I/O error occurs.
         */
        public byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        /**
         * Read data from the input stream into the buffer
         * @throws IOException if an I/O error occurs.
         */
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
	}
	
	 
	public static void  update(long []t, int i, int value) {
		for(;i<t.length;i+= i&-i)
			t[i] += value;
	}
	
	public static long get(long []t, int i) {
		long ans=0;
		for(;i>0;i-= i&-i)
			ans += t[i];
		return ans;
	}
	
	public static long sum(long []t, int l, int r) {
		return get(t, r) - get(t, l-1);
	}
	
	public static void main(String[] args)  throws java.lang.Exception {
			FastReader reader = new FastReader(System.in);
			PrintWriter out = new PrintWriter(System.out, false);
			int N = reader.nextInt();
			long tree[] = new long[N+9];
			for (int i = 1; i <=N; i++) {
				int x = reader.nextInt();
				update(tree, i, x);
			}
			int Q = reader.nextInt();
			while(Q > 0) {
				byte op = reader.read();
				int l = reader.nextInt();
				int r = reader.nextInt();
				if(op == 'q') {
					out.println(sum(tree, l, r));
				}
				else {
					update(tree, l, r);
				}
				Q--;
			}
			out.flush();
	}
}
        private byte[] buffer;     
        private int bufferPointer; 
        private int bytesRead; 
        
        public FastReader(InputStream in) {
            din = in;
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        

        /**
         * Read the next integer from the input stream.
         * @return The next integer.
         * @throws java.io.IOException
         */
        public int nextInt() throws IOException {
            int result = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            while (c >= '0' && c <= '9') {
                result = result * 10 + c - '0';
                c = read();
            }
            if (neg) return -result;
            return result;
        }

        /**
         * Read a line of data from the input stream.
         * @return the next line of data.
         * @throws IOException if an I/O error occurs.
         */
        public String readLine() throws IOException {
            StringBuilder line = new StringBuilder();
            char c;
            while ((c = (char)(read())) != '\n') {
                line.append(c);
            }
            return line.toString();
        }

        /**
         * Read the next byte of data from the input stream.
         * @return the next byte of data, or -1 if the end of the stream is reached.
         * @throws IOException if an I/O error occurs.
         */
        public byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        /**
         * Read data from the input stream into the buffer
         * @throws IOException if an I/O error occurs.
         */
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
	}
	
	 
	public static void  update(long []t, int i, int value) {
		for(;i<t.length;i+= i&-i)
			t[i] += value;
	}
	
	public static long get(long []t, int i) {
		long ans=0;
		for(;i>0;i-= i&-i)
			ans += t[i];
		return ans;
	}
	
	public static long sum(long []t, int l, int r) {
		return get(t, r) - get(t, l-1);
	}
	
	public static void main(String[] args)  throws java.lang.Exception {
			FastReader reader = new FastReader(System.in);
			PrintWriter out = new PrintWriter(System.out, false);
			int pivot = 1000002;
			int N = reader.nextInt();
			long tree[] = new long[2*pivot+1];
			for (int i = 1; i <=N; i++) {
				int x = reader.nextInt();
				update(tree, i+pivot, x);
			}
			int Q = reader.nextInt();
			while(Q > 0) {
				int op = reader.nextInt();
				int l = reader.nextInt();
				if(op == 1) {
					int r = reader.nextInt();
					System.out.println(sum(tree, l+pivot, r+pivot));
				}
				else {
					update(tree, pivot, l);
					pivot--;
				}
				Q--;
			}
			out.flush();
	}
}
