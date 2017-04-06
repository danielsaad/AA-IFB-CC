package ordenacao;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class InsertionsortJava {

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
	    System.out.println("\nInsertionsort!\n");
	    Insertionsort(v);
	    System.out.println("Imprimindo vetor depois da ordenação.\n");
	    for(int i=0;i<n;i++){
	    	 System.out.println("v["+i+"] = "+v.get(i));
	    }
	}

	private static void Insertionsort(List<Integer> v) {
		
		    for( int i=1;i<v.size();i++){
		        int chave = v.get(i);
		        int j=i-1;
		        for( ;j>=0 && v.get(j)>chave;j--){
		        	 v.set(j+1,v.get(j));
		        }
		        v.set(j+1, chave);
		    }
		
	}
	

}