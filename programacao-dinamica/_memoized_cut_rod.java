package ProgramaçãoDinâmica;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class _memoized_cut_rod {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		Integer aux[] = {0,1,5,8,9,10,17,17,20,24,30};
		List<Integer> p = Arrays.asList(aux);
		int n;
		System.out.println("Digite o tamanho da barra: ");
		n = entrada.nextInt();
		System.out.println( memoized_cut_rod(p,n));

	}

	private static int memoized_cut_rod(List<Integer> p, int n) {
		List<Integer> r = new ArrayList<Integer>(Collections.nCopies(n+1, -1));
		return memoized_cut_rod_helper(p,n,r);
	}

	private static int memoized_cut_rod_helper(List<Integer> p, int n,List<Integer> r) {
		if(r.get(n)>0){
			return r.get(n);
		}
		if(n==0){
			return 0;
		}
		int q = -1;
		for(int i=1;i<=n;i++){
			q = Math.max(q,p.get(i) + memoized_cut_rod_helper(p,n-i,r));
		}
		r.set(n, q);
		return r.get(n);
	}

}
