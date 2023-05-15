package ordenacao;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class bubblesort {
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
	    System.out.println("\nBubblesort!\n");
	    Bubblesort(v);
	    System.out.println("Imprimindo vetor depois da ordenação.\n");
	    for(int i=0;i<n;i++){
	    	 System.out.println("v["+i+"] = "+v.get(i));
	    }
	}

	private static void Bubblesort(List<Integer> v) {
	    boolean trocou = true;
	    for( int i=0;i<v.size() && trocou;i++){
	        trocou = false;
	        for( int j=0;j<v.size()-1;j++){
	            if(v.get(j)>v.get(j+1)){
	            	int t = v.get(j);
	  	  	      v.set(j, v.get(j+1));
	  	  	     v.set(j+1, t);
	                trocou = true;
	            }
	        }
	    }	
	}
}
