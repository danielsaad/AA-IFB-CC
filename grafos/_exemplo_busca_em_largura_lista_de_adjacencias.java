package grafos;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class _exemplo_busca_em_largura_lista_de_adjacencias {
	static void dfs(	List<List<Integer>> g, int v){

	    int white = 0; //v�rtice n�o processado
	    int grey = 1; //v�rtice em processamento
	    int black = 2; // v�rtice processado

	    List<Integer> color = new ArrayList<Integer>(Collections.nCopies(g.size(), white));//cor
	    List<Integer> d = new ArrayList<Integer>(Collections.nCopies(g.size(), Integer.MAX_VALUE));//cor
		List<Integer> pai = new ArrayList<Integer>(Collections.nCopies(g.size(), -1));//informa��o do pai
		
	    d.set(v, 0);
	    color.set(v, grey);
	    Queue<Integer> q = new LinkedList<Integer>();
	    q.offer(v);
	    while(!q.isEmpty()){
	        int u = q.peek(); // retira o n� da fila
	        q.poll();
	        System.out.println("N� visitado = "+u);
	        System.out.println("Pai do n� = "+pai.get(u));
	        System.out.println( "Dist�ncia da origem "+v+" = "+d.get(u));

	        for(int j=0;j<g.get(u).size();j++){ //percorre a lista de adjac�ncias
	        	 int w = g.get(u).get(j);  //retira o n� adjacente
		            if(color.get(w)==white){  //se o n� ainda n�o foi visitado, inclue ele na lista
		            	color.set(w, grey); // marca o n� como em processamento
		            	pai.set(w, u); //atualiza o pai
		            	d.set(w, d.get(u)+1); //atualiza a dist�ncia
	                q.offer(w); //coloca o n� na fila
	            }
	        }
	        color.set(u, black);        
	    }
	}
	
	public static void main(String[] args) {
		List<List<Integer>> g = new ArrayList<List<Integer>>();
		g.add(new ArrayList<Integer>());
		g.add(new ArrayList<Integer>());
		g.add(new ArrayList<Integer>());
		g.add(new ArrayList<Integer>());
		g.add(new ArrayList<Integer>());
		g.get(0).add(1);
		g.get(0).add(4);
		g.get(1).add(2);
		g.get(1).add(3);
		g.get(2).add(3);
		g.get(2).add(4);
		g.get(3).add(3);
		g.get(3).add(3);
		g.get(4).add(0);
		g.get(4).add(1);

		dfs(g, 4);
	}
}
