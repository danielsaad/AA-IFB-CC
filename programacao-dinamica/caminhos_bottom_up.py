def build_dp_table(n:int):
    dp_table = [ [0 for _ in range(n)] for _ in range(n) ]
    for i in range(n):
        dp_table[i][0]=1
        dp_table[0][i]=1
    
    for i in range(1,n):
        for j in range(1,n):
            dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1]

    return dp_table


if __name__=='__main__':
    dp = build_dp_table(5)
    for l in dp:
        print(l)
