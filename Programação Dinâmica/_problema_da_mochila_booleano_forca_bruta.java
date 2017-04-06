package ProgramaçãoDinâmica;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class _problema_da_mochila_booleano_forca_bruta {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		int n;
		int H;

		System.out.println("Digite o numero de namorados: ");
		n= entrada.nextInt();
		System.out.println( "Digite o numero de horas disponiveis para namoro: ");
		H= entrada.nextInt();
		List<Integer> h = new ArrayList<Integer>(Collections.nCopies(n, 0));
		List<Integer> b = new ArrayList<Integer>(Collections.nCopies(n, 0));
		for(int i=0;i<n;i++){
			System.out.println("Digite o numero de horas demandadas pelo namorado " + i + ": ");
			h.set(i, entrada.nextInt());
			System.out.println("Digite o beneficio dado pelo namorado " + i + ": ");
			b.set(i, entrada.nextInt());
		}
		System.out.println("A quantidade de beneficio máxima é de: " + mochila_booleana_forca_bruta(H,h,b,n-1) );

	}

	private static int mochila_booleana_forca_bruta(int H, List<Integer> h,List<Integer> b, int i) {
		if(i==-1){
			return 0;
		}
		int v1,v2;
		v1 = v2 = -1;
		if(H-h.get(i)>=0){
			v1 = mochila_booleana_forca_bruta(H-h.get(i),h,b,i-1)+b.get(i);
		}
		v2 = mochila_booleana_forca_bruta(H,h,b,i-1);
		return (Math.max(v1,v2));
	}

}
