def build_dp_table(n:int):
    dp_table = [ 0 for _ in range(n) ]
    dp_table[0] = 1
    dp_table[1] = 1 
    
    for i in range(2,n):
        dp_table[i] = dp_table[i-1]+dp_table[i-2]

    return dp_table


if __name__=='__main__':
    dp = build_dp_table(5)
    print(dp)
