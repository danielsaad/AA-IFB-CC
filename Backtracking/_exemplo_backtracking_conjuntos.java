package Backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class _exemplo_backtracking_conjuntos {

	public static void main(String[] args) {
		
		Integer aux[] = {1,2,3,4,5,6,7,8,9,10};
		List<Integer> v = Arrays.asList(aux);
		
		backtrack(v);
	}

	private static void backtrack(List<Integer> v) {
		List<Boolean> b = new ArrayList<Boolean>(Collections.nCopies(v.size(), false));
		backtrack_helper(v,b,0);
		
	}

	private static void backtrack_helper(List<Integer> v, List<Boolean> b, int i) {
		if(i==v.size()){
			System.out.print( "Subconjunto: ");
			for(int j=0;j<b.size();j++){
				if(b.get(j)==true){
					System.out.print(v.get(j) + " ");
				}
			}
			System.out.println();
		}
		else{
			b.set(i, true) ;
			backtrack_helper(v,b,i+1);
			b.set(i, false);
			backtrack_helper(v,b,i+1);
		}
		
	}

}
