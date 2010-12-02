/**
 *
 * @author Murilo Nascimento
 */
public class Teste {

	public static void main(String[] args) {
		String[] data = new String[5];
		Manipuladora mani = new Manipuladora();
		data = mani.getAgenteInfo(1,1);
		for(int i=0;i<5;i++){
			System.out.println(data[i]);
		}
		System.out.print("\n\n");
		data = mani.getAgenteInfo(1,13);
		for(int i=0;i<5;i++){
			System.out.println(data[i]);
		}

		System.out.print("\n\n=========================================\n");
		mani.setAgentePersonalidade(1, 14, "personalidade(grosseiro)");
		data = mani.getAgenteInfo(1,14);
		for(int i=0;i<5;i++){
			System.out.println(data[i]);
		}
	}
}
