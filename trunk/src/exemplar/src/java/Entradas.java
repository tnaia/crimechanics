import javax.swing.JOptionPane;


public class Entradas {
	
	private int[] opcoes = new int[2];
	
	public Entradas(){
		
	}
	
	public int[] getOps(String agName){

		for(int i=0;i<2;i++){
			opcoes[i] = -1;
		}
		
		try{
		opcoes[0] = Integer.parseInt(JOptionPane.showInputDialog("personalidade("+agName+")\n0 - grosseiro" +
				"\n1 - simpatico\n2 - teimoso\n3 - educado"));
		opcoes[1] = Integer.parseInt(JOptionPane.showInputDialog("estado("+agName+")\n0 - bravo\n1 - feliz" +
				"\n2 - assustado\n3 - indiferente"));
		}catch(Exception e){
			e.printStackTrace();
		}
		
		/*for(int i=0;i<2;i++){
			System.out.println(opcoes[i]);
		}*/
		
		return opcoes;
	}

}
