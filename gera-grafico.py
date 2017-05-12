import numpy as np
import matplotlib.pyplot as plt

def f(domain):
	l=[]
	for i in domain:
		l.append(np.math.factorial(i))
	return l

def g(domain):
	return domain**domain

#define intervalo e amostragem
amostra = np.arange(1, 10, 1)

plt.plot(amostra, f(amostra), 'b-',label="f(n)")
plt.plot(amostra, g(amostra) , 'r--',label="g(n)")
plt.xlabel("n")
plt.ylabel("Passos")
plt.title("Comportamento de Funções") 


lgd = plt.legend(loc='upper center', bbox_to_anchor=(0.5,0),fancybox=True, shadow=True)
plt.tight_layout()

plt.show()
