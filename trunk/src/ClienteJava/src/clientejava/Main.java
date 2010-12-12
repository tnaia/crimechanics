/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package clientejava;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

/**
 *
 * @author Murilo
 */
public class Main {

    private Socket cliente;
    private ObjectOutputStream output;
    private ObjectInputStream input;
    private String mensagem = "";
    /**
     * @param args the command line arguments
     */

    public void runCliente(){
        try{
        connectToServer();
        getStreams();
        processConnection();}catch(Exception e){
            e.printStackTrace();
        }
    }

    private void connectToServer() throws IOException{
        System.out.println("conectando. . .");
        cliente = new Socket("localhost",9999);
        System.out.println("conectado a: "+cliente.getInetAddress().getHostName() );
    }

    private void getStreams() throws IOException{
        output = new ObjectOutputStream(cliente.getOutputStream());
        output.flush();
        input = new ObjectInputStream(cliente.getInputStream());
    }

    private void processConnection() throws IOException{

        do{
        try {
           mensagem = (String) input.readObject();
            System.out.println("MENSAGEM: "+mensagem);
        } catch (Exception e) {
            e.printStackTrace();
        }

        }while (!mensagem.equals("13"));
        closeConnection();
    }

    private void closeConnection() throws IOException{
        System.out.println("terminando conexao. . . ");
        output.close();
        input.close();
        cliente.close();
    }


}
