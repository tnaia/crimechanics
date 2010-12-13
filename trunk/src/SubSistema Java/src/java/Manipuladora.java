import java.io.*;

/*Esta classe faz a leitura e escrita em arquivos de texto dos agentes*/
public class Manipuladora {

	
	public Manipuladora(){}
	
	/*este m�todo monta o nome do arquivo de entrada conforme o ID e o tipo do agente
	 * em quest�o.*/
	private String montaNomeArquivo(int tipo, int id){
		String nomeArquivo = "";
		File arquivo;
		String aux1,aux2;
		nomeArquivo = "agente";
		aux1 = Integer.toString(tipo);
		aux2 = Integer.toString(id);
		nomeArquivo = nomeArquivo + aux1 + aux2 + ".txt";
		//System.out.println("Nome gerado: "+nomeArquivo);
		return nomeArquivo;
	}
	
	/*Este m�todo retorna todas as informa��es relevantes do agente identificado por tipo e id*/
	public String[] getAgenteInfo(int tipo, int id){

        String[] dados = new String[7];
        if(tipo==1||tipo==3||(tipo==2&&id<50)){
        dados[0] = getAgentNome(tipo, id);//ler nome
		if(dados[0]==null){System.out.println("ERRO NA LEITURA! (NOME)");return null;}
		dados[1] = getAgentPersonalidade(tipo, id);//ler personalidade
		if(dados[1]==null){System.out.println("ERRO NA LEITURA! (PERSONALIADE)");return null;}
		dados[2] = getAgentPorcentagemPersonalidade(tipo, id);//ler probabilidade de mudan�a de personalidade
		if(dados[2]==null){System.out.println("ERRO NA LEITURA!(PROB PERSONA)");return null;}
		dados[3] = getAgentEstadoPsicologico(tipo, id);//ler estado psicol�gico
		if(dados[3]==null){System.out.println("ERRO NA LEITURA!(ESTADO PSICO)");return null;}
		dados[4] = getAgentPorcentagemEstadoPsicologico(tipo, id);//ler estado psicol�gico
		if(dados[4]==null){System.out.println("ERRO NA LEITURA!(ESTADO PSICO)");return null;}
            }

        if(tipo==3){
        dados[5] = getAgentSuspectLevel(tipo, id);//ler nome
		if(dados[5]==null){System.out.println("ERRO NA LEITURA! (NIVEL SUSPEITA)");return null;}
            }
            
		if(tipo==2&&id<50){
        dados[6] = getAgentIndole(tipo, id);//ler nome
		if(dados[6]==null){System.out.println("ERRO NA LEITURA! (INDOLE-POLICIAL)");return null;}
            }

     	return dados;
	}
		
	public String getAgentNome(int tipo, int id){
		String info;String nomeArquivo;
		nomeArquivo = montaNomeArquivo(tipo, id);
		info = lerLinha("@N",nomeArquivo);//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@N");return null;}
				return info;
	}
	
	public String getAgentPersonalidade(int tipo, int id){
		String info;String nomeArquivo;
		nomeArquivo = montaNomeArquivo(tipo, id);
		info = lerLinha("@P",nomeArquivo);//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@P");return null;}
		return info;
	}
	
	public String getAgentEstadoPsicologico(int tipo, int id){
		String info;String nomeArquivo;
		nomeArquivo = montaNomeArquivo(tipo, id);
		info = lerLinha("@EP",nomeArquivo);//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@EP");return null;}
		return info;
	}
	
	public String getAgentPorcentagemPersonalidade(int tipo, int id){
		String info;String nomeArquivo;
		nomeArquivo = montaNomeArquivo(tipo, id);
		info = lerLinha("@FP",nomeArquivo);//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@FP");return null;}
		return info;
	}
	
	public String getAgentPorcentagemEstadoPsicologico(int tipo, int id){
		String info;String nomeArquivo;
		nomeArquivo = montaNomeArquivo(tipo, id);
		info = lerLinha("@FEP",nomeArquivo);//ler personalidade
		if(info==null){System.out.println("ERRO NA LEITURA!@FP");return null;}
		return info;
	}

        public String getAgentSuspectLevel(int tipo, int id){
            String info;String nomeArquivo;
			nomeArquivo = montaNomeArquivo(tipo, id);
            info = lerLinha("@NS",nomeArquivo);
            if(info==null){System.out.println("ERRO NA LEITURA! @NS");return null;}
            return info;
        }
        
        public String getAgentIndole(int tipo, int id){
	        String info;String nomeArquivo;
			nomeArquivo = montaNomeArquivo(tipo, id);
            info = lerLinha("@IND",nomeArquivo);
            if(info==null){System.out.println("ERRO NA LEITURA! @IND");return null;}
            return info;
	        }
	
	/*Este m�todo l� e devolve uma linha espec�fica, determinada pela String (tipoLinha)*/
	private String lerLinha(String tipoLinha, String nomeArquivo){
		String linha = "";
		String saida[]= new String[2];
		try{
		File arquivo = new File(nomeArquivo);
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

	/*Este m�todo altera a personalidade do agente identificado por tipo e id*/
	public void setAgentePersonalidade(int tipo, int id, String personalidade){
		setCaracteristicaAgente(tipo, id, personalidade, "@P");
	}
	
	
	/*Este m�todo altera o estado psicologico do agente identificado por tipo e id*/
	public void setAgenteEstadoPsicologico(int tipo, int id, String estadoPsicologico){
		setCaracteristicaAgente(tipo, id, estadoPsicologico, "@EP");
	}

        /*Este m�todo altera a personalidade do agente identificado por tipo e id*/
	public void setNivelSuspeita(int tipo, int id, int suspeita){
            if(tipo!=3){System.out.println("OPERACAO INVALIDA!");return;}
            setCaracteristicaAgente(tipo, id, Integer.toString(suspeita), "@NS");
	}

	/*Este m�todo faz a escreve um arquivo temporario do agente identificado pelo tipo e pelo id
	 * Atualizando alguma caracteristica (personalidade, estado psicologico, etc) e depois,
	 * atualiza o arquivo original*/
	private void setCaracteristicaAgente(int tipo, int id, String caracteristica, String idCaracteristica){
		
		try{
			String nomeArquivo = montaNomeArquivo(tipo, id);
			String linha = "po";
			File arquivo = new File(nomeArquivo);
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
	
	/*M�todo que faz a atualizac�o do arquivo original*/
	private void atualizaArquivo(File original, File temp){

		if(!(original.delete())){System.out.print("NAO DELETADO!");}
		if(!(temp.renameTo(original))){System.out.print("NAO RENOMEADO!");}
		
	}

}//fim da classe