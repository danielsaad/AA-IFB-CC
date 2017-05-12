import numpy as np
import matplotlib.pyplot as plt


def f(n):
        #INSIRA AQUI A FUNCAO f(n)
        return  np.math.factorial(n)    #fatorial de n

def g(n):
        #INSIRA AQUI A FUNCAO g(n)
        return n**(10*n)                        #n elevado a 10n

#define intervalo e amostragem
amostra = np.arange(0, 100, 1)

plt.plot(amostra, [f(n) for n in amostra ], 'b-',label="f(n)")
plt.plot(amostra, [g(n) for n in amostra ] , 'r--',label="g(n)")
plt.xlabel("n")
plt.ylabel("Passos")
plt.title("Comportamento de Funções")


lgd = plt.legend(loc='upper center', bbox_to_anchor=(0.5,0),fancybox=True, shadow=True)
plt.tight_layout()

plt.show()
