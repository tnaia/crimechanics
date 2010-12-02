/**
 *
 * @author Murilo Nascimento
 */
import java.io.*;

/*Esta classe faz a leitura e escrita em arquivos de texto dos agentes*/
public class Manipuladora {

	private String nomeArquivo = "";
	private File arquivo;

	public Manipuladora(){}

	/*este método monta o nome do arquivo de entrada conforme o ID e o tipo do agente
	 * em questão.*/
	private void montaNomeArquivo(int tipo, int id){
		String aux1,aux2;
		nomeArquivo = "agente";
		aux1 = Integer.toString(tipo);
		aux2 = Integer.toString(id);
		nomeArquivo = nomeArquivo + aux1 + aux2 + ".txt";
		//System.out.println("Nome gerado: "+nomeArquivo);
	}

	/*Este método retorna todas as informações relevantes do agente identificado por tipo e id*/
	public String[] getAgenteInfo(int tipo, int id){
		String[] dados = new String[5];
		dados[0] = getAgentNome(tipo, id);//ler nome
		if(dados[0]==null){System.out.println("ERRO NA LEITURA! (NOME)");return null;}
		dados[1] = getAgentPersonalidade(tipo, id);//ler personalidade
		if(dados[1]==null){System.out.println("ERRO NA LEITURA! (PERSONALIADE)");return null;}
		dados[2] = getAgentPorcentagemPersonalidade(tipo, id);//ler probabilidade de mudança de personalidade
		if(dados[2]==null){System.out.println("ERRO NA LEITURA!(PROB PERSONA)");return null;}
		dados[3] = getAgentEstadoPsicologico(tipo, id);//ler estado psicológico
		if(dados[3]==null){System.out.println("ERRO NA LEITURA!(ESTADO PSICO)");return null;}
		dados[4] = getAgentPorcentagemEstadoPsicologico(tipo, id);//ler estado psicológico
		if(dados[4]==null){System.out.println("ERRO NA LEITURA!(ESTADO PSICO)");return null;}
		return dados;
	}

	public String getAgentNome(int tipo, int id){
		String info;
		montaNomeArquivo(tipo, id);
		info = lerLinha("@N");//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@N");return null;}
		return info;
	}

	public String getAgentPersonalidade(int tipo, int id){
		String info;
		montaNomeArquivo(tipo, id);
		info = lerLinha("@P");//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@P");return null;}
		return info;
	}

	public String getAgentEstadoPsicologico(int tipo, int id){
		String info;
		montaNomeArquivo(tipo, id);
		info = lerLinha("@EP");//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@EP");return null;}
		return info;
	}

	public String getAgentPorcentagemPersonalidade(int tipo, int id){
		String info;
		montaNomeArquivo(tipo, id);
		info = lerLinha("@FP");//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@FP");return null;}
		return info;
	}

	public String getAgentPorcentagemEstadoPsicologico(int tipo, int id){
		String info;
		montaNomeArquivo(tipo, id);
		info = lerLinha("@FEP");//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@FP");return null;}
		return info;
	}

	/*Este método lê e devolve uma linha específica, determinada pela String (tipoLinha)*/
	private String lerLinha(String tipoLinha){
		String linha = "";
		String saida[]= new String[2];
		try{
		arquivo = new File(nomeArquivo);
		FileReader leitorArquivo = new FileReader(arquivo);
		BufferedReader ler = new BufferedReader(leitorArquivo);
		while(!(linha.contains(tipoLinha))){linha = ler.readLine();}
		saida = linha.split(" ");

		//System.out.println("retornando: "+saida[1]);
		ler.close();leitorArquivo.close();

		return saida[1];
		}catch(Exception e){
			e.printStackTrace();return null;/*em caso de erro*/}
	}

	/*Este método altera a personalidade do agente identificado por tipo e id*/
	public void setAgentePersonalidade(int tipo, int id, String personalidade){
		setCaracteristicaAgente(tipo, id, personalidade, "@P");
	}


	/*Este método altera o estado psicologico do agente identificado por tipo e id*/
	public void setAgenteEstadoPsicologico(int tipo, int id, String estadoPsicologico){
		setCaracteristicaAgente(tipo, id, estadoPsicologico, "@EP");
	}

	/*Este método faz a escreve um arquivo temporario do agente identificado pelo tipo e pelo id
	 * Atualizando alguma caracteristica (personalidade, estado psicologico, etc) e depois,
	 * atualiza o arquivo original*/
	private void setCaracteristicaAgente(int tipo, int id, String caracteristica, String idCaracteristica){

		try{
			montaNomeArquivo(tipo, id);
			String linha = "po";
			arquivo = new File(nomeArquivo);
			File temp = new File("temp.txt");
			FileReader leitorArquivo = new FileReader(arquivo);
			FileWriter escritorArquivo = new FileWriter(temp);
			BufferedReader ler = new BufferedReader(leitorArquivo);
			BufferedWriter escrever = new BufferedWriter(escritorArquivo);

			while((linha=ler.readLine()) != null){
				if(!(linha.trim().contains(idCaracteristica))){
					escrever.write(linha);
					escrever.flush();
					escrever.newLine();
				}else{
					escrever.write(idCaracteristica+" "+caracteristica);
					escrever.flush();
					escrever.newLine();
				}
			}

			escrever.close();escritorArquivo.close();
			ler.close();leitorArquivo.close();

			atualizaArquivo(arquivo, temp);
		}catch(Exception e){e.printStackTrace();}
	}

	/*Método que faz a atualizacão do arquivo original*/
	private void atualizaArquivo(File original, File temp){

		if(!(arquivo.delete())){System.out.print("NAO DELETADO!");}
		if(!(temp.renameTo(arquivo))){System.out.print("NAO RENOMEADO!");}

	}

}//fim da classe
