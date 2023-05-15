package ED;

import java.util.Stack;

/**
 * A pilha � uma Estrutura de Dados que permite inser��o no in�cio e remo��o no in�cio.
 * Segue a filosofia LIFO (�ltimo a entrar � o primeiro a sair).
 *
 * A complexidade de inser��o/remo��o � O(1).
 * Normalmente a pilha � implementada atrav�s de uma lista duplamente ligada.
 *
 * M�todos para utiliza��o:
 * push ()- Insere no fim.
 * pop() - Remove no in�cio
 * peek() - acessa o elemento do topo da pilha.
 * empty() - retorna verdadeiro se a pilha est� vazia e falso caso contr�rio
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
