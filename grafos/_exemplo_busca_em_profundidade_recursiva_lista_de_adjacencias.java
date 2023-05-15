package grafos;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class _exemplo_busca_em_profundidade_recursiva_lista_de_adjacencias {
	static Integer white = 0; // vértice não processado
	static Integer grey = 1; // vértice em processamento
	static Integer black = 2; // vértice processado

	public static void main(String[] args) {

		List<List<Integer>> g = new ArrayList<List<Integer>>();
		g.add(new ArrayList<Integer>());
		g.add(new ArrayList<Integer>());
		g.add(new ArrayList<Integer>());
		g.add(new ArrayList<Integer>());
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

	public static void dfs(List<List<Integer>> g, int v) {
		List<Integer> color = new ArrayList<Integer>(Collections.nCopies(g.size(), white));
		List<Integer> pai = new ArrayList<Integer>(Collections.nCopies(g.size(), -1));
		dfs_helper(g, color, pai, v);

	}

	private static void dfs_helper(List<List<Integer>> g, List<Integer> color,
			List<Integer> pai, int v) {
		color.set(v, grey);
		System.out.println("Nó visitado = " + v);
		System.out.println("Pai de " + v + " = " + pai.get(v));

		for (int i = 0; i < g.get(v).size(); i++) {
			int w = g.get(v).get(i);
			if (color.get(w) == white) {
				pai.set(w, v);
				dfs_helper(g, color, pai, w);
			}
		}
		color.set(v, black);

	}

}
