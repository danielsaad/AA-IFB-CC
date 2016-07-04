package ProgramaçãoDinâmica;

import java.util.Scanner;

public class _lcs_forca_bruta {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		String x,y;
		System.out.println("Digite as sequencias X e Y: ");
		x=entrada.nextLine();
		y=entrada.nextLine();
		System.out.println("A maior subsequencia comum de X e Y tem tamanho: " 
		+ lcs_forca_bruta(x,y,x.length(),y.length()));

	}
	public static int lcs_forca_bruta(String x,String y, int n,int m){
		if(n==0 || m==0){
			return 0;
		}
		if(x.charAt(n-1)==y.charAt(m-1)){
			return 1+lcs_forca_bruta(x,y,n-1,m-1);
		}
		else{
			return Math.max(lcs_forca_bruta(x,y,n-1,m),lcs_forca_bruta(x,y,n,m-1));
		}
	}
}
