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
	    
	    @Override
	    public boolean equals(Object o) {
	    	if(o == this) {
	    		return true;
	    	}
	    	
	    	if(!(o instanceof Point)) {
	    		return false;
	    	}
	    	
	    	Point p = (Point) o;
	    	
	    	return Integer.compare(x, p.x) == 0 && Integer.compare(y, p.y) == 0;
	    }
	    
	}
		
	public static class BFS{
		static int move_x[] = {1,-1,2,2,1,-1,-2,-2};
		static int move_y[] = {2,2,1,-1,-2,-2,1,-1};
		static int limit = 8;
		int[][] M =  new int[limit][limit];
		
		public int knight_move(Point x, Point y) {
			Queue<Point> cola = new LinkedList<>();
			cola.add(x);
			for (int[] row: M)
				Arrays.fill(row, -1);
			M[x.x][x.y] = 0;
			while(!cola.isEmpty()) {
				Point tmp = cola.remove();
				int _x = tmp.x;
				int _y = tmp.y;
				if(tmp.equals(y)) {
					return M[_x][_y];
				}
				for(int i=0;i<8;i++) {
					int __x = _x + move_x[i];
					int __y = _y + move_y[i];
					if(__x >= 0 && __x <limit && __y >= 0 && __y<limit && M[__x][__y] == -1) {
						cola.add(new Point(__x,__y));
						M[__x][__y] = M[_x][_y] + 1;
					}
				}
				
			}
			return -1;
		}
		
	}
	
	public static void main(String[] args)  throws java.lang.Exception {
			FastReader reader = new FastReader(System.in);
			PrintWriter out = new PrintWriter(System.out, false);
			int cas = reader.nextInt();
			while(cas-- > 0) {
				String[] line = reader.readLine().split(" ");
				String l = line[0];
				String r = line[1];
				BFS bfs = new BFS();
				Point x = new Point(l.charAt(0)-'a', l.charAt(1)-'1');
				Point y = new Point(r.charAt(0)-'a', r.charAt(1)-'1');
				out.println(bfs.knight_move(x, y));
			}
			out.flush();
	}
}
