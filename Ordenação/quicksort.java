package ordenacao;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class quicksort {
	public static void main(String[] args) {

	   
	    int n = 1000;
	    Random rng = new Random();// random-number engine used (Mersenne-Twister in this case)
	    List<Integer> v = new ArrayList<Integer>();
	    for(int i=0;i<n;i++){
	        v.add(rng.nextInt(1000));//gera de 0 a 999
	    }
	    System.out.println("Imprimindo vetor antes da ordenação.\n");
	    for(int i=0;i<n;i++){
	       System.out.println("v["+i+"] = "+v.get(i));
	    }
	    System.out.println("\nQuicksort!\n");
	    quicksort(v);
	    System.out.println("Imprimindo vetor depois da ordenação.\n");
	    for(int i=0;i<n;i++){
	    	 System.out.println("v["+i+"] = "+v.get(i));
	    }
	}

	private static void quicksort(List<Integer> v) {
		 recursive_quicksort(v,0,v.size()-1);
		
	}

	private static void recursive_quicksort(List<Integer> v, int l, int r) {
		if(l<r){
		    int p = partition(v,l,r);
		    recursive_quicksort(v,l,p-1);
		    recursive_quicksort(v,p+1,r);
		}
		
	}

	private static int partition(List<Integer> v, int l, int r) {

	    int k = l; //marca o fim da primeira partição
	    int i = l; //elemento a ser analizado
	    int pivo = r; //pivo é o elemento do final
	    while(i<r){
	        if(v.get(i)<=v.get(pivo)){
	          int t = v.get(k);
	  	      v.set(k, v.get(i));
	  	      v.set(i,t);
	            k++;
	        }
	        i++;
	    }
	    int t = v.get(k);
	    v.set(k, v.get(i));
	    v.set(i,t);//colocamos o pivo na posição correta
	    return k; //retornamos a posição do pivo
	}
}
