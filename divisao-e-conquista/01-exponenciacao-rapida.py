def main():
    base, exp = map(int, input().split())
    print(exponenciacao_rapida(base, exp))


def exponenciacao_rapida(base: int, exp: int) -> int:
    """
    T(n) = \Theta 1, n = 0
    T(n) = T(n / 2) + \Theta 1 => \Theta lg n < o(n)
    """
    res: int
    if exp == 0:
        return 1
    if exp & 1:
        res = base * (exponenciacao_rapida(base, exp // 2) ** 2)
    else:
        res = (exponenciacao_rapida(base, exp // 2) ** 2)

    return res


if __name__ == "__main__":
    main()
