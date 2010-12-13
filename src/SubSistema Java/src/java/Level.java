// Environment code for project Agents_tcc

import jason.asSyntax.*;
import jason.environment.*;
import java.util.logging.*;
import javax.swing.*;

public class Level extends Environment {

	Manipuladora man = new Manipuladora();
	//Comunicadora con = new Comunicadora();
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
        estimulos[7] = "inquestionavel";
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
        		testes(1, "a114");
        	}else{System.out.println("Ocorreu um erro na inicialização do agente "+agName);}
        }
        
        if(action.toString().contains("startPolicial")){
	        	if(inicializaPolicial(agName)){
		        	System.out.println("Agente "+agName+"inicializado!");
		        	}else{System.out.println("Ocorreu um erro na inicialização do agente "+agName);}
	        }
        
        if(action.toString().contains("comeca")){
        	System.out.println("agente "+agName+" inicializado!\n");
                String info;
                //teste
                //info = "atividadeSuspeitaP(a310)";
                //reportePolicial(agName,info);
                //teste
                //info = "atividadeSuspeitaL(banco)";
                //reportePolicial(agName,info);
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

        if(action.toString().contains("atualizarP")){
        	String novaP = action.toString().substring(11);
        	novaP = novaP.trim();
        	novaP = novaP.substring(0,novaP.length()-1);
        	novaP = "personalidade("+novaP+")";
        	atualizarP(agName,novaP);
        }
        
        
        if(action.toString().contains("resposta")){
        	System.out.println("respondendo . . .");
        	
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
    	String[] dados = new String[7];
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

    private boolean inicializaPolicial(String agName){
	    int[] numeros = new int[2];
    	try{
	    	String[] dados = new String[7];
    		numeros = this.getNumeros(agName);
    		dados = man.getAgenteInfo(numeros[0], numeros[1]);
    		addPercept(agName,Literal.parseLiteral(dados[1]));
    		addPercept(agName,Literal.parseLiteral(dados[3]));
    		addPercept(agName,Literal.parseLiteral(dados[6]));
    		return true;}catch(Exception e){
    		e.printStackTrace();return false;
    	}
	    }
    
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
           //clear percepts
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
	    	//clear percepts
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
    	int[] mensagem;
    	int tipo,id;
    	dados = getNumeros(nome);
    	tipo = dados[0];
    	id = dados[1];
    	//ENVIAR A MESNAGEM CORRESPONDENTE AO C++
    	//mensagem = montaMensagem(2,dados[0]*100+dados[1],dependerRESPOSTA);
    	//Comunicadora.send(mensagem);
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
	    
	 private boolean atualizarP(String nome, String novaP){
		try{
	    int[] dados;
    	int tipo,id;
    	String personalidadeAtual;
    	dados = getNumeros(nome);
    	tipo = dados[0];
    	id = dados[1];
    	personalidadeAtual = man.getAgentPersonalidade(tipo,id);
    	removePercept(nome,Literal.parseLiteral(personalidadeAtual));
    	addPercept(nome,Literal.parseLiteral(novaP));
    	man.setAgentePersonalidade(tipo, id, novaP);
    	return true;}catch(Exception e){e.printStackTrace();System.out.println("ERRO NA ATUALIZACAO DE PERSONALIDADE");return false;}
	     
		 }//fim do método
    
    //chega pelo subsitema C++
    public void estimularAgente(String nome, int indexEstimulo){
	    String aux = nome.substring(1);int val;
	    val = Integer.parseInt(aux);
	    //System.out.println("ID: "+val);
	    if(val<200&&indexEstimulo==0){System.out.println("UM CIVIL NAO PODE SER SUBORNADO!!!");return;}
    	addPercept(nome,Literal.parseLiteral("estimulo("+estimulos[indexEstimulo]+")"));
    }//fim do método

    //chega pelo subsitema C++
    public void reportePolicial(String receptor, String informacao){
        addPercept(receptor, Literal.parseLiteral(informacao));
    }//fim do método
    
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
    
    //método que aguarda entradas do Cpp
    private void receberMensagens(){
	    int[] valores = new int[10];
	    int id,index;
	    int[] ops = new int [10];
	    String nome;
	    //valores = con.getMensagem();
	    
	    switch(valores[0]){ 
		    case 1:	montarMensagem(1);break;//inicializa dialogo
		    case 2:	id = valores[1]; index = valores[2];
		    		nome = "a"+Integer.toString(id);estimularAgente(nome, index);break;//estimula agente
		    case 3:	id = valores[1];for(int k=0;k<valores[0];k++){
			    			ops[k] = valores[k+2];}
		    		break;//oferece escolhas
		    default: break;}
	    }//fim do método
    
	    
    private int[] montarMensagem(int tipo){
	   	int[] mensagem = new int[2];

	    if(tipo==1){//returnIdAgente
	    mensagem[0] = 1;
	    if(Math.random()>0.5){
	    mensagem[1] = 100+ (10 + (int)(10*Math.random()));
    	}else{
	    mensagem[1] = 200+ (20 + (int)(10*Math.random()));
    		}}
    	else{mensagem[0] = 0; mensagem[1] = 0; System.out.println("TIPO DE MENSAGEM INVALIDO!");}
	    return mensagem;}
	    
	    private int[] montarMensagem(int tipo, int id1, int id2){
	   	int[] mensagem = new int[4];

	    if(tipo==2){//returnEscolha
	    mensagem[0] = 2;
	    mensagem[1] = id1;
	    mensagem[2] = id2;
	        		}
	    if(tipo==3){//returnAcaoPolicia
		mensagem[0] = 2;
	    mensagem[1] = id1;
	    mensagem[2] = id2;
		    }
	    return mensagem;}
    
    /** Called before the end of MAS execution */
    @Override
    public void stop() {
        super.stop();
    }
    
    
    public void testes(int tipo, String agente){
        String entrada;
        int val = 0;
        int[] dados;
    	int tipoA,id;
    	dados = getNumeros(agente);
    	tipoA = dados[0];
    	id = dados[1];
    	
        
        switch(tipo){
            case 1:
            	while(val!=99){
                System.out.println("Estimulos ao agente: "+agente);
                JOptionPane.showMessageDialog(null, man.getAgentEstadoPsicologico(tipoA,id)+"\n"
                        +man.getAgentPersonalidade(tipoA, id),agente, JOptionPane.INFORMATION_MESSAGE);
                entrada = JOptionPane.showInputDialog(null,"2 - AMIGAVEL\n3 - ELOGIAR"
                        + "\n4 - INSULTAR\n5 - TIMIDO\n6 - INQUISITIVO"
                        + "\n7 - SUSPEITO\n8 - INQUESTIONAVEL\n\nENTRADA: ");
                val = Integer.parseInt(entrada);
                val = val - 1;
                if(val<=8&&val>0){
                estimularAgente(agente, val);}
            }
                break;
            case 2:
                System.out.println("Estimulos ao policial: "+agente);
                                JOptionPane.showMessageDialog(null, man.getAgentEstadoPsicologico(1,14)+"\n"
                        +man.getAgentPersonalidade(1, 14),agente, JOptionPane.INFORMATION_MESSAGE);
                entrada = JOptionPane.showInputDialog(null,"1 - SUBORNO\n2 - AMIGAVEL\n"
                        + "3 - ELOGIAR"+ "\n4 - INSULTAR\n5 - TIMIDO\n6 - INQUISITIVO"
                        + "\n7 - SUSPEITO\n8 - INQUESTIONAVEL\n\nENTRADA: ");
                val = Integer.parseInt(entrada);
				
                break;
            case 3:
                System.out.println("Estimulos aos policiais do blackboard");
                entrada = JOptionPane.showInputDialog(null,"1 - ATIVIDADE SUSPEITA\n"
                        + "2 - TENTATIVA ROUBO\n"+ "3 - ROUBO"+"\nENTRADA: ");
                val = Integer.parseInt(entrada);

                break;
            default: System.out.println("TIPO INVALIDO!");break;
        }
    }


    
}