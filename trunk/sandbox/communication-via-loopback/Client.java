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

	    for( r = 0; r < 2; r++ )
		{
		    byte aux = data[ r ];
		    data[ r ] = data [ 4 -r -1 ];
		    data[ 4 -r -1 ] = aux;
		}
	    System.out.println("(Java): Received data (hex): " + Integer.toHexString(buffer.getInt()) );

	    // Then return the same long int (32 bits)
	    buffer.clear();
	    Integer i;
	    if( args.length > 0 )
		i = new Integer( args[0] );
	    else
		i = 42; // Default value

	    System.out.println ("(Java): sending " + i + " (" + Integer.toHexString(i) + ").");
	    buffer.putInt(i);
	    OutputStream out = s.getOutputStream();
	    out.write(data);
	    s.close();
	}
	catch(Exception ex) {
	    ex.printStackTrace();
	}
    }
}
