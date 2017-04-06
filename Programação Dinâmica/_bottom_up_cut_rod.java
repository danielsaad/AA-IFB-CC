package ProgramaçãoDinâmica;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class _bottom_up_cut_rod {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		Integer aux[] = {0,1,5,8,9,10,17,17,20,24,30};
		List<Integer> p = Arrays.asList(aux);
		int n;
		System.out.println("Digite o tamanho da barra: ");
		n = entrada.nextInt();
		System.out.println( bottom_up_cut_rod(p,n));
	}
	
	
	public static int bottom_up_cut_rod(List<Integer> p, int n){
		List<Integer> r = new ArrayList<Integer>(Collections.nCopies(n+1, -1));
		r.set(0, 0);
		for(int j=1;j<=n;j++){
			int q = -1;
			for(int k=1;k<=j;k++){
				q = Math.max(q,p.get(k)+r.get(j-k));
			}
			r.set(j, q);
		}
		return r.get(n);
	}
}
