package grafos;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class exemplo_djikstra {
	public static class no {
		int id;
		int d;

		public no(int id, int d) {
			this.id = id;
			this.d = d;
		}

	}

	public static Comparator<no> Compare = new Comparator<no>() {

		public int compare(no c1, no c2) {
			Integer aa = c1.d;
			return aa.compareTo(c2.d);
		}

	};

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);

		List<List<Integer>> g = new ArrayList<List<Integer>>();
		List<List<Integer>> w = new ArrayList<List<Integer>>();
		int n = entrada.nextInt();
		int m = entrada.nextInt();
		for (int i = 0; i < n; i++) {
			g.add(new ArrayList<Integer>());
			w.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < m; i++) {
			System.out.println("Digite a aresta (u,v,peso): ");
			int u, v, peso;
			u = entrada.nextInt();
			v = entrada.nextInt();
			peso = entrada.nextInt();
			g.get(u).add(v);
			g.get(v).add(u);
			w.get(u).add(peso);
			w.get(v).add(peso);

		}
		djikstra(g, w, 0);
	}

	private static void djikstra(List<List<Integer>> g, List<List<Integer>> w,
			int v) {
		List<Integer> color = new ArrayList<Integer>(Collections.nCopies( g.size(), 0));
		List<Integer> distancia = new ArrayList<Integer>(Collections.nCopies( g.size(), Integer.MAX_VALUE));
		Queue<no> q = new PriorityQueue<>(g.size(), Compare);
		distancia.set(v, 0);
		no n = new no(v, distancia.get(v));
		q.offer(n);

		while (!q.isEmpty()) {
			n = q.element();
			q.poll();
			int u = n.id;
			if (color.get(u) == 2) {
				continue;
			}
			color.set(u, 1);
			System.out.println("Retirei o nó " + u);
			System.out.println("Distância de " + v + " até " + u + " = " + distancia.get(u));
			for (int i = 0; i < g.get(u).size(); i++) {
				int z = g.get(u).get(i);
				int peso_aresta = w.get(u).get(i);
				System.out.println("Vizinho de " + u + " = " + z);
				System.out.println("Distancia de " + v + " até " + z + " = " + distancia.get(z));
				System.out.println("Peso da aresta de " + u + " a " + z + " = " + peso_aresta);
				
				if (color.get(z) != 2 && distancia.get(z) >  distancia.get(u)+peso_aresta) {
					distancia.set(z, distancia.get(u)+peso_aresta);
					
					System.out.println("Atualizando a distância de " + z + " para " + distancia.get(z));
					no ins = new no(z, distancia.get(z));
					q.offer(ins);
				}
			}
			color.set(u, 2);
		}
	}

}
