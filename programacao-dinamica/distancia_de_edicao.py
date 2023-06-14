def build_dp_table(X:str,Y:str) -> list[list[int]]:
    dp = [ [ 0 for _ in range(len(Y)+1)] for _ in range(len(X)+1)]
    for i in range(len(Y)+1):
        dp[0][i] = i
    for i in range(len(X)+1):
        dp[i][0] = i
    for i in range(1,len(X)+1):
        for j in range(1,len(Y)+1):
            if X[i-1] == Y[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1    
    return dp

def trace(dp:list[list[int]],X:str,Y:str)->None:
    i = len(X)
    j = len(Y)
    ans_x = []
    ans_y = []
    while i>0 or j>0:
        if X[i-1]==Y[j-1]:
            ans_x.append(X[i-1])
            ans_y.append(Y[j-1])
            i = i-1
            j = j-1
        else:
            min_value = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
            if min_value == dp[i-1][j-1]:
                ans_x.append(X[i-1])
                ans_y.append(Y[j-1])
                i -= 1
                j -= 1
            elif min_value == dp[i][j-1]:
                ans_x.append('_')
                ans_y.append(Y[j-1])
                j -= 1
            else:
                ans_x.append(X[i-1])
                ans_y.append('_')
                i-=1
    ans_x.reverse()
    ans_y.reverse()
    print(ans_x)
    print(ans_y)
if __name__=='__main__':
    X = 'sunday'
    Y = 'saturday'
    dp = build_dp_table(X,Y)
    for l in dp:
        print(l)
    trace(dp,X,Y)
