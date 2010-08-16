import java.net.*;
import java.io.*;
import java.nio.ByteBuffer;

public class Client {
    public static void main(String[] args) {

	System.out.println ("This is the client (Java).\n");
	try {
	    InetSocketAddress addr = new InetSocketAddress("localhost", 9999);
	    Socket s = new Socket();
	    // Differently from the C++ version, in this case we attempt to connect
	    // with an infinite timeout
	    s.connect(addr, 0);
	    // Once connected, we try to receive one long int (32 bits)
	    InputStream inp = s.getInputStream();
	    byte[] data = new byte[4];
	    ByteBuffer buffer = ByteBuffer.wrap(data);
	    buffer.clear();
	    int r = 0;
	    do {
		r += inp.read(data, r, 4-r);
	    }
	    while (r < 4);
	    System.out.print("(Java): Received data: " + Integer.toHexString(buffer.getInt()) );
	    //	    System.out.println (buffer.getInt());
	    /*
	      Isto
	      System.out.println(Integer.toString(data, 16).toUpperCase());
	      deveria imprimir os bytes, mas a compilação diz
	      javac Client.java
	      Client.java:28: cannot find symbol
	      symbol  : method toString(byte[],int)
	      location: class java.lang.Integer
	      System.out.println(Integer.toString(data, 16).toUpperCase());
	                                        ^
	    */
	    // Then return the same long int (32 bits)
	    buffer.clear();
	    System.out.println ("(Java): sending 42 (" + Integer.toHexString(42) + ").");
	    buffer.putInt(42);
	    OutputStream out = s.getOutputStream();
	    out.write(data);
	    s.close();
	}
	catch(Exception ex) {
	    ex.printStackTrace();
	}
    }
}
