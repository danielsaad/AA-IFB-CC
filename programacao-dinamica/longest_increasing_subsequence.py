def build_dp_table(V:list[int])->tuple[list[int],list[int]]:
    dp = [1 for _ in range(len(V))]
    trace = [-1 for _ in range(len(V))]
    for i in range(1,len(V)):
        for j in range(i):
            if V[j]< V[i]:
                if(dp[i]< dp[j]+1):
                    dp[i] = dp[j]+1
                    trace[i] = j
    return (dp,trace)

def get_subsequence(V:list[int],trace:list[int],dp:list[int])->None:
    ans = []
    max_value = max(dp)
    idx = -1
    for i,x in enumerate(dp):
        if x== max_value:
            idx = i
    while idx!=-1:
        ans.append(V[idx])
        idx = trace[idx]
    ans.reverse()
    print(ans)

if __name__=='__main__':
    V = [-7,-8,2,-10,9,3,1,8,2]
    dp,trace = build_dp_table(V)
    print(dp)
    print(max(dp))
    get_subsequence(V,trace,dp)