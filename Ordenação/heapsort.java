package ordenacao;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class HeapsortJava {

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
	    System.out.println("\nHeapsort!\n");
	    Heapsort(v);
	    System.out.println("Imprimindo vetor depois da ordenação.\n");
	    for(int i=0;i<n;i++){
	    	System.out.println("v["+i+"] = "+v.get(i));
	    }
	}

	private static void Heapsort(List<Integer> v) {
		makeheap(v);
	    for(int i=v.size()-1;i>0;i--){
	    	int t = v.get(0);
	  	      v.set(0, v.get(i));
	  	     v.set(i, t);
	        heapify(v,0,i);
	    }
	}

	private static void makeheap(List<Integer> v) {
		for(int i=v.size()/2;i>=0;i--){
		        heapify(v,i,v.size());
		}
	}

	private static void heapify(List<Integer> v, int i, int heapsize) {

	    int l,r;
	    while(i<heapsize){
	        l = 2*i+1;
	        r = 2*i+2;
	        int maior = i;
	        if(l<heapsize && v.get(l)>v.get(i)){
	            maior = l;
	        }
	        if(r<heapsize && v.get(r)>v.get(maior)){
	            maior = r;
	        }
	        if(maior!=i){
	        	int t = v.get(maior);
		  	      v.set(maior, v.get(i));
		  	     v.set(i, t);
	            i = maior;
	        }
	        else{
	            break;
	        }
	    }	
	}
}
