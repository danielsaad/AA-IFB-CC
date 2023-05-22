import numpy as np


def main():
    matriz: list[list] = [
        [2, 2],
        [2, 2]]
    matriz_b: list[list] = [
        [2],
        [2]]
    mul_matriz(matriz, matriz_b)

    # print(multiplicacao_matriz_otimizada(matriz, 31))


def multiplicacao_matriz_otimizada(matriz: list[list], k: int) -> list[list]:
    # \theta lg k
    tmp_matriz: list[list] = list()
    # Caso base
    if k == 1:
        return matriz
    # Expoente impar
    elif k & 1:
        tmp_matriz = multiplicacao_matriz_otimizada(matriz, k//2)
        tmp_matriz = np.matmul(matriz, np.matmul(tmp_matriz, tmp_matriz))
    # Expoente par
    else:
        tmp_matriz = multiplicacao_matriz_otimizada(matriz, k//2)
        tmp_matriz = np.matmul(tmp_matriz, tmp_matriz)

    return tmp_matriz


def mul_matriz(matriz_a: list[list], matriz_b: list[list]) -> list[list]:
    # \theta n³
    matriz_c: list[list] = list()

    for i in range(len(matriz_a)):
        matriz_c.append([])
        for j in range(len(matriz_b[i])):
            tmp: float = 0
            for k in range(len(matriz_b)):
                tmp += matriz_a[i][k] * matriz_b[k][j]
            matriz_c[i].append(tmp)
    return matriz_c


if __name__ == "__main__":
    main()
