// Environment code for project Agents_tcc

import jason.asSyntax.*;
import jason.environment.*;
import java.util.logging.*;

public class Level extends Environment {

	Manipuladora man = new Manipuladora();
    private Logger logger = Logger.getLogger("Agents_tcc."+Level.class.getName());

    /** Called before the MAS execution with the args informed in .mas2j */
    @Override
    public void init(String[] args) {
        super.init(args);
        System.out.println("inicializando agentes. . .");
    }

    @Override
    public boolean executeAction(String agName, Structure action) {
        logger.info("executing: "+action+", but not implemented!");
        if(action.toString().contains("start")){
        	addPercept(agName,Literal.parseLiteral("personalidade(simpatico)"));
        	addPercept(agName,Literal.parseLiteral("estadoPsicologico(feliz)"));
        	addPercept(agName,Literal.parseLiteral("estimulo(negativo)"));
        }
        
        if(action.toString().contains("responder")){
        	System.out.println("respondendo . . .");
        	responder(agName);
        	
        }
        return true;
    }

    
    /*Aqui vou implementar as actions dos agentes!!*/
    
    //este método implementa a ação de responder
    private void responder(String nome){
    	int[] dados;
    	int tipo,id;
    	String estadoPsicologico = "estadoPsicologico(desconfortavel)";
    	dados = getNumeros(nome);
    	tipo = dados[0];
    	id = dados[1];
    	removePercept(nome,Literal.parseLiteral("estadoPsicologico(feliz)"));
    	addPercept(nome,Literal.parseLiteral(estadoPsicologico));
    	man.setAgenteEstadoPsicologico(tipo, id, estadoPsicologico);
    }
    
    private int[] getNumeros(String nome){
    	int[] dados = new int[2];
    	String sub = nome.substring(1, 2);
    	dados[0] = Integer.parseInt(sub);
    	sub = nome.substring(2, 4);
    	dados[1] = Integer.parseInt(sub);
    	//System.out.println(nome+" "+sub);
    	//System.out.println(dados[0]+"\t"+dados[1]);
    	return dados;
    }
    
    /** Called before the end of MAS execution */
    @Override
    public void stop() {
        super.stop();
    }
}
