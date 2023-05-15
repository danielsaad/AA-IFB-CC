package ED;

import java.util.ArrayDeque;
import java.util.Deque;

public class _exemplo_deque {
	/**
	 * O deque pode ser visto como uma fila em que � poss�vel inser��o/remo��o no in�cio e no final.
	 *
	 * A complexidade de inser��o/remo��o � O(1), em ambos os lados.
	 * Normalmente o deque � implementado atrav�s de uma lista duplamente ligada.
	 *
	 * M�todos para utiliza��o:
	 * addFirst() - Insere no in�cio.
	 * addLast() - Insere no final
	 * removeFirst() - Remove no in�cio.
	 * removeLast() - Remove no final.
	 * peek() - acessa o primeiro elemento.
	 * back() - acessa o �ltimo elemento.
	 * isEmpty() - retorna verdadeiro se o deque est� vazio e falso caso contr�rio
	 */
	public static void main(String[] args) {
		Deque<Integer> d = new ArrayDeque<Integer>();
		    d.addFirst(1); //inser��o na frente
		    d.addFirst(2); //inser��o na frente
		    d.addLast(4); //inser��o no final
		    d.addLast(3); //inser��o no final
		    while(!d.isEmpty()){
		        int elem = d.peek();
		        System.out.print("Elemento do in�cio do deque " + elem + "\n");
		        d.removeFirst();
			}

	}

}
