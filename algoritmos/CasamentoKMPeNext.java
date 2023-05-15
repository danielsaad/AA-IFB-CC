package provaGrafo;

public class CasamentoKMPeNext {
	public static void main(String[] args) {
		int n = 11;
		int next[] = new int[n + 1];
		prefix("xyxyyxyxyxx", n, next);
		for (int i = 0; i < next.length; i++) {
			System.out.print(next[i] + " ");
		}
		String texto="yxyxxyxyxyxyxyyxyxyxxxy",padrao="xyxyyxyxyxx";
		System.out.println();
		kmp(texto, padrao, texto.length(), padrao.length(), next);
	}

	public static void prefix(String substring, int tam_string, int next[]) {

		next[0] = 0; // aux[0] é sempre 0
		int j = 0; // tamanho do maior prefixo que é sufixo
		int i = 1;

		while (i < tam_string) {
			if (substring.charAt(i) == substring.charAt(j)) {
				j++;
				next[i] = j;
				i++;
			} else {
				if (j != 0) {
					j = next[j - 1];
				} else {
					next[i] = 0;
					i++;
				}
			}
		}
	}

	public static void kmp(String texto,String padrao, int tamTexto,int tamPadrao, int next[]){
	
		int indexP=0, indexT=0;
		while(indexT<tamTexto){
			if(padrao.charAt(indexP)==texto.charAt(indexT)){
				indexP++;
				indexT++;
			}
			if (indexP==tamPadrao) {
				System.out.println("Padrao encotrado na posição " + (indexT-indexP));
				indexP= next[indexP-1];
				
			}else if(indexT<tamTexto && padrao.charAt(indexP)!= texto.charAt(indexT)) {
				if (indexP!=0) {
					indexP=next[indexP-1];
				}else {
					indexT++;
				}
			}
			
		}
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
