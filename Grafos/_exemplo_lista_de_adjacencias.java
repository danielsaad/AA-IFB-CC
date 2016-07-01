package grafos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class _exemplo_lista_de_adjacencias {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
	    int n,m;
	    List<List<Integer>> l_adj = new ArrayList<List<Integer>>();

	    System.out.println("Digite o número de vértices: ");
	    n=Integer.parseInt(entrada.readLine());
	    System.out.println("Digite o número de arestas: ");
	    m=Integer.parseInt(entrada.readLine());
	  
	    for (int i = 0; i < n; i++) {
	    	l_adj.add(new ArrayList<Integer>());
		}
	    
	    for(int i=0;i<m;i++){
	        int a,b;
	        System.out.print("Dados da Aresta " + i + "\n");
	        System.out.print("Digite o no de origem (0 a " + n + "): ");
	        a=Integer.parseInt(entrada.readLine());
	        System.out.print("Digite o no de destino (0 a " + n + "): ");
	        b=Integer.parseInt(entrada.readLine());
	        l_adj.get(a).add(b);
	        // l_adj.get(b).add(a); //Descomentar se o grafo não for direcionado
	    }
	    System.out.print("\n\nImprimindo Lista de Adjacências \n\n");
	    for(int i=0;i<l_adj.size();i++){
	    	 System.out.print(i + " -> ");
	        for(int j=0;j<l_adj.get(i).size();j++){
	        	 System.out.print( l_adj.get(i).get(j));
	        	 System.out.print( " -> ");
	        }
	        System.out.println();
	    }

	}

}
