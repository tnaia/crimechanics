// Environment code for project Agents_tcc

import jason.asSyntax.*;
import jason.environment.*;
import java.util.logging.*;

public class Level extends Environment {

	Manipuladora man = new Manipuladora();
	Comunicadora con = new Comunicadora();
    private Logger logger = Logger.getLogger("Agents_tcc."+Level.class.getName());

    /*Para melhorar o desempenho os tipos de estimulos e respostas foram copiados
     * para dentro do código em vetores de strings onde os índices representam
     * a linha do arquivo correspondente.*/
    private String[] reacoes = new String[10];
    private String[] estimulos = new String[10];
    private String[] lugares = new String[10];
    
    
    /** Called before the MAS execution with the args informed in .mas2j */
    @Override
    public void init(String[] args) {
        super.init(args);
        estimulos[0] = "propina";
        estimulos[1] = "falaAmigavel";
        estimulos[2] = "elogio";
        estimulos[3] = "insulto";
        estimulos[4] = "falaTimida";
        estimulos[5] = "inquisitivo";
        estimulos[6] = "suspeito";
        reacoes[0] = "aceitarPropina";
        reacoes[1] = "rejeitarPropina";
        reacoes[2] = "insultar";
        reacoes[3] = "elogiar";
        reacoes[3] = "agradecer";
        lugares[0] = "banco";
        lugares[1] = "lojaImportados";
        System.out.println("inicializando agentes. . .\n\n");
    }

    @Override
    public boolean executeAction(String agName, Structure action) {
        logger.info("executing: "+action);
        
        //inicializar crenças e desejos dos civis
        if(action.toString().contains("startCivil")){
        	if(inicializarCivil(agName)){
        		System.out.println("Agente "+agName+" inicializado!");
        		//fazendo um teste
        		estimularAgente(agName, 2);
        	}else{System.out.println("Ocorreu um erro na inicialização do agente "+agName);}
        }
        
        if(action.toString().contains("comeca")){
        	System.out.println("agente "+agName+" inicializado!\n");
                String info;
                //teste
                info = "atividadeSuspeitaP(a310)";
                reportePolicial(agName,info);
                //teste
                info = "atividadeSuspeitaL(banco)";
                reportePolicial(agName,info);
        }
        
        if(action.toString().contains("removerEstimulo")){
	        	String emocao = action.toString().substring(16);
	        	emocao = emocao.trim(); emocao = emocao.substring(0,emocao.length()-1);
	        	String estimulo = "estimulo("+emocao+")";
	        	removerEstimulo(agName,estimulo); 
	        }
        
       if(action.toString().contains("atualizarEP")){
        	String novoEP = action.toString().substring(12);
        	novoEP = novoEP.trim();
        	novoEP = novoEP.substring(0,novoEP.length()-1);
        	novoEP = "estadoPsicologico("+novoEP+")";
        	atualizarEP(agName,novoEP);
        }

        if(action.toString().contains("responder")){
        	System.out.println("respondendo . . .");
        	responder(agName);
        }
        
        if(action.toString().contains("aumentarNivelSuspeita")){
        	String alvo;                
                alvo = action.toString().substring(22, 26);
                aumentarNivelSuspeita(agName, alvo);
        }
        
        if(action.toString().contains("prender")){
        	String alvo;
        	alvo = action.toString().substring(8,12);
        	if(!prenderAgente(agName,alvo)){System.out.println("Ocorreu uma falha durante o decreto da prisao do agente "+alvo);}
        }
        
        if(action.toString().contains("aumentarNivelSeguranca")){
        	String alvo;
        	alvo = action.toString().substring(23);
        	alvo = alvo.trim();alvo=alvo.substring(0, alvo.length()-1);
        	System.out.println("O policial "+agName+" aumentou o nivel de seguranca de: "+alvo);
        }
        
        return true;
    }


    /*Aqui vou implementar as actions dos agentes!!*/
    private boolean inicializarCivil(String agName){
    	String[] dados = new String[5];
    	int[] numeros = new int[2];
    	try{
    		numeros = this.getNumeros(agName);
    		dados = man.getAgenteInfo(numeros[0], numeros[1]);
    		addPercept(agName,Literal.parseLiteral(dados[1]));
    		addPercept(agName,Literal.parseLiteral(dados[3]));
    		return true;}catch(Exception e){
    		e.printStackTrace();return false;
    	}
    }//fim do método

    private boolean aumentarNivelSuspeita(String policial, String alvo){
        try {
            String[] data = new String[7];
            int sus;
            int[] ids = new int[2];
            ids = getNumeros(alvo);
            data = man.getAgenteInfo(ids[0], ids[1]);
            sus = Integer.parseInt(data[5]) + 1;
            if(sus>5)sus=5;
            man.setNivelSuspeita(ids[0],ids[1],sus);
            System.out.println("O policial "+policial+" aumentou o nivel de suspeita sobre o agente "+alvo);
           //o percept deve ser adicionado em todos os policiais
           //a variavel correspondente do agente deve ser atualizada
           //ENVIAR A MESNAGEM CORRESPONDENTE AO C++ 
           addPercept(Literal.parseLiteral("nivelSuspeitaIncrementado("+alvo+","+sus+")"));
           return true;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("OCORREU UM ERRO NA TENTATIVA DE AUMENTAR NIVEL DE SUSPEITA!");
            return false;
        }
    }//fim do método
    
    private boolean prenderAgente(String policial, String alvo){
	    	addPercept(Literal.parseLiteral("prender("+alvo+")"));
	    	System.out.println("O policial "+policial+" decretou a prisao do alvo "+alvo);
	    	//ENVIAR A MESNAGEM CORRESPONDENTE AO C++
	    	return true;
	    }//fim do método
    

	private boolean removerEstimulo(String agente, String estimulo){
		try{
			   removePercept(agente,Literal.parseLiteral(estimulo));
			   return true;
				}catch(Exception e){e.printStackTrace();
				System.out.println("Ocorreu um erro durante a remocao de um estimulo de "+agente);
				return false;}
		}//fim do método
	    
    //este método implementa a ação de responder
    private void responder(String nome){
    	int[] dados;
    	int tipo,id;
    	String estadoPsicologico = "estadoPsicologico(lisonjeado)";
    	dados = getNumeros(nome);
    	tipo = dados[0];
    	id = dados[1];
    	//ENVIAR A MESNAGEM CORRESPONDENTE AO C++
    	//Comunicadora.returnEscolha(agente,escolha)
    }
    
    private boolean atualizarEP(String nome,String novoEP){
	    try{
	    int[] dados;
    	int tipo,id;
    	String estadoAtual;
    	dados = getNumeros(nome);
    	tipo = dados[0];
    	id = dados[1];
    	estadoAtual = man.getAgentEstadoPsicologico(tipo,id);
    	removePercept(nome,Literal.parseLiteral(estadoAtual));
    	addPercept(nome,Literal.parseLiteral(novoEP));
    	man.setAgenteEstadoPsicologico(tipo, id, novoEP);
    	return true;}catch(Exception e){e.printStackTrace();System.out.println("ERRO NA ATUALIZACAO DE EP");return false;}
	    }
    
    //chega pelo subsitema C++
    public void estimularAgente(String nome, int indexEstimulo){
    	addPercept(nome,Literal.parseLiteral("estimulo("+estimulos[indexEstimulo]+")"));
    }

    //chega pelo subsitema C++
    public void reportePolicial(String receptor, String informacao){
        addPercept(receptor, Literal.parseLiteral(informacao));
    }
    
    
    /**Métodos auxiliares**/
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
