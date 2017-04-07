import numpy as np
import matplotlib.pyplot as plt

def f(n):
        l=[]
        for i in n:
		#INSIRA AQUI A FUNCAO f(n) representando-a por f(i)
		l.append( np.math.factorial(i) )
        return l

def g(n):
        l=[]
        for i in n:
		#INSIRA AQUI A FUNCAO g(n) representando-a por g(i)
		l.append( i**i )
	return l

#define intervalo e amostragem
amostra = np.arange(0, 1000, 1)

plt.plot(amostra, f(amostra), 'b-',label="f(n)")
plt.plot(amostra, g(amostra) , 'r--',label="g(n)")
plt.xlabel("n")
plt.ylabel("Passos")
plt.title("Comportamento de Funções") 


lgd = plt.legend(loc='upper center', bbox_to_anchor=(0.5,0),fancybox=True, shadow=True)
plt.tight_layout()

plt.show()
