package grafos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class _exemplo_matriz_de_adjacencias {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
	    int n,m;
	    List<List<Boolean>> m_adj = new ArrayList<List<Boolean>>();

	    System.out.println("Digite o número de vértices: ");
	    n=Integer.parseInt(entrada.readLine());
	    System.out.println("Digite o número de arestas: ");
	    m=Integer.parseInt(entrada.readLine());
	  
	    for (int i = 0; i < n; i++) {
	    	m_adj.add(new ArrayList<Boolean>());
		}
	    for (int i = 0; i < m_adj.size(); i++) {
			for (int j = 0; j < n; j++) {
				m_adj.get(i).add(false);
			}
		}
	    for(int i=0;i<m;i++){
	        int a,b;
	        System.out.print("Dados da Aresta " + i + "\n");
	        System.out.print("Digite o no de origem (0 a " + n + "): ");
	        a=Integer.parseInt(entrada.readLine());
	        System.out.print("Digite o no de destino (0 a " + n + "): ");
	        b=Integer.parseInt(entrada.readLine());
	        m_adj.get(a).set(b,true);
	        //  m_adj.get(b).set(a,1); //Descomentar se o grafo não for direcionado
	    }

	    System.out.print( "\n\nImprimindo Matriz de Adjacências \n\n");
	    for(int i=0;i<m_adj.size();i++){
	    	 System.out.print(i + " -> ");
	        for(int j=0;j<m_adj.get(i).size();j++){
	            if(m_adj.get(i).get(j)){
	            	 System.out.print(j);
	            			 System.out.print(" -> ");
	            }
	        }
	        System.out.println();
	    }
	    System.out.println();
	}

}
