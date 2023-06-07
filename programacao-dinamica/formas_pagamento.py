def build_dp_table(coins: list[int], W: int) -> list[list[int]]:
    dp_table = [[0 for _ in range(W+1)] for _ in range(len(coins)+1)]
    dp_table[0][0] = 1
    for i in range(1, len(coins)+1):
        for j in range(0, W+1):
            if (j < coins[i-1]):
                dp_table[i][j] = dp_table[i-1][j]
            else:
                dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-coins[i-1]]
    return dp_table


if __name__ == '__main__':
    coins = [1, 5, 10, 25, 50, 100]
    for w in [10, 25, 50,100,10000]:
        dp = build_dp_table(coins, w)
        for l in dp:
            print(l)
