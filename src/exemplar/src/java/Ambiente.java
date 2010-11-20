// Environment code for project exemplar

import jason.asSyntax.*;
import jason.environment.*;
import java.util.logging.*;

public class Ambiente extends Environment {

    private Logger logger = Logger.getLogger("exemplar."+Ambiente.class.getName());
    
    Entradas iniciais = new Entradas();
    private String[] personalidade = new String[4];
	private String[] estadoEmocional = new String[4];
	private int[] ops = new int[2];
	
    /** Called before the MAS execution with the args informed in .mas2j */
    @Override
    public void init(String[] args) {
        super.init(args);
        for(int i=0;i<2;i++)ops[i] = -1;
        personalidade[0] = "personalidade(grosso)";
		personalidade[1] = "personalidade(simpatico)";
		personalidade[2] = "personalidade(teimoso)";
		personalidade[3] = "personalidade(educado)";
		estadoEmocional[0] = "estadoEmocional(bravo)";
		estadoEmocional[1] = "estadoEmocional(feliz)";
		estadoEmocional[2] = "estadoEmocional(assustado)";
		estadoEmocional[3] = "estadoEmocional(indiferente)";
	
        addPercept(Literal.parseLiteral("percept(demo)"));
    }

    @Override
    public boolean executeAction(String agName, Structure action) {
        logger.info("executing: "+action+", but not implemented!");
        
        if(action.toString().equals("definir(status)")){
        System.out.print("definindo a personalidade inicial de ");
        System.out.println(agName);
        ops = iniciais.getOps(agName);
        addPercept(agName, Literal.parseLiteral(personalidade[ops[0]]));
        addPercept(agName, Literal.parseLiteral(estadoEmocional[ops[1]]));
        if(agName.equals("murilo"))addPercept(agName,Literal.parseLiteral("insultado"));
        }
        return true;
    }

    /** Called before the end of MAS execution */
    @Override
    public void stop() {
        super.stop();
    }
}
