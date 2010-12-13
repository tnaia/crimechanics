import java.net.*;
import java.io.*;
import java.nio.ByteBuffer;

public class Comunicadora {

	private Socket s;
	private byte[] data = new byte[4];
	private ByteBuffer buffer = ByteBuffer.wrap(data);
	
	public Comunicadora(){
		try {
	    int port = 9999;
	    InetSocketAddress addr = new InetSocketAddress("localhost", port);
	    s = new Socket();
	    // Differently from the C++ version, in this case we attempt to connect
	    // with an infinite timeout
	    s.connect(addr, 0);}catch(Exception e){System.out.println("FALHA NA CONEXAO COM O SERVIDOR!");e.printStackTrace();}
		}//fim do construtor
		
	public void recebeMensagem(){
		try{
		InputStream inp = s.getInputStream();
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
		
		switch(buffer.getInt()){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default: System.out.println("MENSAGEM RECEBIDA INVALIDA!");break;
		}
		
	}catch(Exception e){e.printStackTrace();System.out.println("ERRO DURANTE A RECEPCAO DAS MENSAGENS!");}
	}//fim do método
	
	public boolean enviaMensagem(int[] dados){
		
		try{
		// Then return the same long int (32 bits)
	    buffer.clear();

		for(int i=0;i<dados[0];i++){
	    System.out.println ("(Java): sending " + i + " (" + Integer.toHexString(i) + ").");
	    buffer.putInt(dados[i]);}
	    OutputStream out = s.getOutputStream();
	    out.write(data);return true;
		}catch(Exception e){e.printStackTrace();System.out.println("ERRO DURANTE O ENVIO DAS MENSAGENS!");return false;}
		
	}//fim do método
		
	public void encerrarConexao(){
		try{s.close();}catch(Exception e){e.printStackTrace();}
		}//fim do método
	
}//fim da classe
