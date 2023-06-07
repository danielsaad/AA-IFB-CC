def build_dp_table(v: list[int], w: list[int], W: int) -> list[list[int]]:
    n = len(v)
    dp_table = [[0 for _ in range(W+1)] for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(0, W+1):
            if (j < w[i-1]):
                dp_table[i][j] = dp_table[i-1][j]
            else:
                dp_table[i][j] = max(dp_table[i-1][j],dp_table[i-1][j-w[i-1]]+v[i-1])
    return dp_table


if __name__ == '__main__':
    v = [100, 20, 60, 40]
    w = [3, 2, 4, 1]
    for W in [3, 5, 6, 7]:
        dp = build_dp_table(v, w, W)
        for l in dp:
            print(l)
        print('')
