package ED;

import java.util.Stack;

/**
 * A pilha é uma Estrutura de Dados que permite inserção no início e remoção no início.
 * Segue a filosofia LIFO (último a entrar é o primeiro a sair).
 *
 * A complexidade de inserção/remoção é O(1).
 * Normalmente a pilha é implementada através de uma lista duplamente ligada.
 *
 * Métodos para utilização:
 * push ()- Insere no fim.
 * pop() - Remove no início
 * peek() - acessa o elemento do topo da pilha.
 * empty() - retorna verdadeiro se a pilha está vazia e falso caso contrário
 */

public class _exemplo_pilha {

	public static void main(String[] args) {
		Stack<Integer> s = new Stack<Integer>(); 
		s.push(2);
		s.push(5);
		s.push(4);
		while(!s.empty()){
			int elem = s.peek();
			s.pop();
			System.out.println("Elemento do topo = " + elem + "\n");
		}
	}

}
