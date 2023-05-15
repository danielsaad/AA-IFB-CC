package ProgramaçãoDinâmica;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class _lcs_top_down {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		String x,y;
		System.out.println("Digite as sequencias X e Y: ");
		x=entrada.nextLine();
		y=entrada.nextLine();
		System.out.println("A maior subsequencia comum de X e Y tem tamanho: " 
		+ lcs(x,y) );

	}

	private static Integer lcs(String x, String y) {
		List<List<Integer>> c =	new ArrayList<List<Integer>>(Collections.nCopies(x.length(),
				new ArrayList<Integer>(Collections.nCopies(y.length(),-1))));
		//vector<vector<int>> c(x.size(),     vector<int>(y.size(),-1));
		return(lcs_top_down(x,y,x.length(),y.length(),c));
	}

	private static Integer lcs_top_down(String x, String y,int n,int m, List<List<Integer>> c) {
		if(n==0 || m==0){
			return 0;
		}
		if(c.get(n-1).get(m-1)!=-1){
			return c.get(n-1).get(m-1);
		}
		if(x.charAt(n-1)==y.charAt(m-1)){
			c.get(n-1).set(m-1, 1+ lcs_top_down(x,y,n-1,m-1,c));
			return  c.get(n-1).get(m-1);
		}
		else{
			c.get(n-1).set(m-1, Math.max(lcs_top_down(x,y,n-1,m,c),lcs_top_down(x,y,n,m-1,c)));
			return c.get(n-1).get(m-1);
		}
	}

}
