import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

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
	
	public static class Point
	{
	    int x,y;
	    Point(int a, int b){  x =a ;  y = b;  }
	    
	}
		
	public static class BFS{
		static int move_x[] = {1,-1,2,2,1,-1,-2,-2};
		static int move_y[] = {2,2,1,-1,-2,-2,1,-1};
		static int limit = 1000;
		int[][] M =  new int[limit][limit];
		
		public void knight_move(int x, int y) {
			Queue<Point> cola = new LinkedList<>();
			cola.add(new Point(x,y));
			for (int[] row: M)
				Arrays.fill(row, -1);
			M[x][y] = 0;
			while(!cola.isEmpty()) {
				Point tmp = cola.remove();
				int _x = tmp.x;
				int _y = tmp.y;
				for(int i=0;i<8;i++) {
					int __x = _x + move_x[i];
					int __y = _y + move_y[i];
					if(__x >= 0 && __x <limit && __y >= 0 && __y<limit && M[__x][__y] == -1) {
						cola.add(new Point(__x,__y));
						M[__x][__y] = M[_x][_y] + 1;
					}
				}
				
			}
			
		}
		
	}
	
	public static void main(String[] args)  throws java.lang.Exception {
			FastReader reader = new FastReader(System.in);
			PrintWriter out = new PrintWriter(System.out, false);
			BFS bfs = new BFS();
			bfs.knight_move(0, 0);
			int n = reader.nextInt();
			while(n-- >0) {
				int x = reader.nextInt();x--;
				int y = reader.nextInt();y--;
				out.println(bfs.M[x][y]);
			}
			out.flush();
	}
}
