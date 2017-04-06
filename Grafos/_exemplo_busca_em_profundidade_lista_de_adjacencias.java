package grafos;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;

public class _exemplo_busca_em_profundidade_lista_de_adjacencias {
	static void dfs(	List<List<Integer>> g, int v){
	    int white = 0; //vértice não processado
	    int grey = 1; //vértice em processamento
	    int black = 2; // vértice processado
	    List<Integer> color = new ArrayList<Integer>(Collections.nCopies(g.size(), white));
		List<Integer> pai = new ArrayList<Integer>(Collections.nCopies(g.size(), -1));
		
	    color.set(v, grey);
	    Deque<Integer> s = new ArrayDeque<Integer>();
	    s.push(v);
	    while(!s.isEmpty()){
	        int u = s.peek(); // retira o nó da pilha
	        s.pop();
	        System.out.println("Nó visitado = "+u);
	        System.out.println("Pai do nó = "+pai.get(u));
	        for(int j=0;j<g.get(u).size();j++){ //percorre a lista de adjacências
	            int w = g.get(u).get(j); //retira o nó adjacente
	            if(color.get(w)==white){ //se o nó ainda não foi visitado, inclue ele na lista
	               color.set(w, grey); // marca o nó como em processamento
	                pai.set(w, u); //atualiza o pai
	                s.push(w); //coloca o nó na pilha
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
