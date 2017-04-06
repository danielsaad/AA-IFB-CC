package ordenacao;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MergesortJava {


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
	    System.out.println("\nMergesort!\n");
	    mergesort(v, 0, v.size()-1);

	    System.out.println("Imprimindo vetor depois da ordenação.\n");
	    for(int i=0;i<n;i++){
	    	 System.out.println("v["+i+"] = "+v.get(i));
	    }
	}

	static public void mergesort(List<Integer> v, int esq, int dir)  {
      int mid;
    
      if (dir > esq)
      {
        mid = (dir + esq) / 2;
        mergesort(v, esq, mid);
        mergesort(v, (mid + 1), dir);
    
        merge(v, esq, (mid+1), dir);
      }
    }
	 static public void merge(List<Integer> v, int esq, int mid, int dir)  {
		 List<Integer> temp = new ArrayList<Integer>();
		 for (int i = 0; i < v.size(); i++) {
			temp.add(0);
		}
        int i, left_end, num_elements, tmp_pos;
    
        left_end = (mid - 1);
        tmp_pos = esq;
        num_elements = (dir - esq + 1);
    
        while ((esq <= left_end) && (mid <= dir))
        {
            if (v.get(esq)<= v.get(mid))
                temp.set(tmp_pos++,v.get(esq++));
            else
            	  temp.set(tmp_pos++, v.get(mid++));
        }
    
        while (esq <= left_end)
        	  temp.set(tmp_pos++, v.get(esq++));
 
        while (mid <= dir)
        	  temp.set(tmp_pos++, v.get(mid++));
 
        for (i = 0; i < num_elements; i++)
        {
            v.set(dir, temp.get(dir));
            dir--;
        }
    }
	

	
}
