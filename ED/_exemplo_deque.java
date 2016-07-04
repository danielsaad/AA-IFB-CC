package ED;

import java.util.ArrayDeque;
import java.util.Deque;

public class _exemplo_deque {
	/**
	 * O deque pode ser visto como uma fila em que é possível inserção/remoção no início e no final.
	 *
	 * A complexidade de inserção/remoção é O(1), em ambos os lados.
	 * Normalmente o deque é implementado através de uma lista duplamente ligada.
	 *
	 * Métodos para utilização:
	 * addFirst() - Insere no início.
	 * addLast() - Insere no final
	 * removeFirst() - Remove no início.
	 * removeLast() - Remove no final.
	 * peek() - acessa o primeiro elemento.
	 * back() - acessa o último elemento.
	 * isEmpty() - retorna verdadeiro se o deque está vazio e falso caso contrário
	 */
	public static void main(String[] args) {
		Deque<Integer> d = new ArrayDeque<Integer>();
		    d.addFirst(1); //inserção na frente
		    d.addFirst(2); //inserção na frente
		    d.addLast(4); //inserção no final
		    d.addLast(3); //inserção no final
		    while(!d.isEmpty()){
		        int elem = d.peek();
		        System.out.print("Elemento do início do deque " + elem + "\n");
		        d.removeFirst();
			}

	}

}
